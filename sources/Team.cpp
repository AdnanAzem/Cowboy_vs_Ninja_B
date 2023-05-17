#include "Team.hpp"
#include <typeinfo>
namespace ariel{

    // =================================== Constructors ===================================
    // Team::Team(){
         
    // }

    Team::Team(Character* leader):captin(leader){
        this->add(captin);
        captin->setIsMember(true);
    }
    // =================================== End Constructors ===================================


    // =================================== Helper Functions ===================================
    vector<Character *> Team::sortTeam(vector<Character *> listOfMembers) const{ // sort the team -> first cowboys then ninjas
        vector<Character *> newListOfMembers;
        //first cowboys:
        for (Character* member : listOfMembers) {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) {
                newListOfMembers.push_back(cowboy);
            }
        }
        //second ninjas:
        for (Character* member : listOfMembers) {
            if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
                newListOfMembers.push_back(ninja);
            }
        }
        return newListOfMembers;
    }

    void Team::changeLeader(){ // change the leader
        double minDistance = std::numeric_limits<double>::max();
        Character* closestFighter = nullptr;
        for (Character* fighter : members) {
            if (fighter->isAlive()) {
                double distance = fighter->distance(captin);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestFighter = fighter;
                }
            }
        }
        captin = closestFighter;
    }

    Character* Team::closest(Team *team) { // return the closest enemy character from the leader
        Character* closestTeammate = nullptr;
        double minDistance = std::numeric_limits<double>::max();
        for (Character* teammate : team->members) {
            if (teammate->isAlive()) {
                double distance = captin->distance(teammate);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestTeammate = teammate;
                }
            }
        }
        return closestTeammate;
    }
    // =================================== End Helper Functions ===================================


    // =================================== Team Functions ===================================
    void Team::add(Character* newMember){ // add member to the team
        if(newMember == nullptr){ // throw error if the input is null
            throw runtime_error("Null Character!!!");
        }
        if (newMember->getIsMember()) { // throw error if the input is already in team
            throw runtime_error("Already in Team!!!");
        }
        if (this->members.size() >= 10) { // throw error if size of team bigger or equal 10
            throw runtime_error("Team is Full!!!");
        } 
        else { // add member to the team and sort the team -> first cowboys the ninjas
            this->members.push_back(newMember);
            newMember->setIsMember(true);
            sortTeam(this->members);
        }
    }

    void Team::attack(Team* enemyTeam){
        if(enemyTeam == nullptr){ // check if we receive a null
            throw std::invalid_argument("Enemy Team is Null");
        }
        if(!stillAlive()){ // check if the team is not alive
            throw std::runtime_error("The Team is Dead");
        }
        if(!enemyTeam->stillAlive()){ // check if the enemy team is not alive
            throw std::runtime_error("Enemy Team is Dead");
        }
        if (!captin->isAlive()) { // check if the leader is not alive
                this->changeLeader();
        }
        // if(!enemyTeam->captin->isAlive()){ // check if the enemy leader is not alive
        //     enemyTeam->changeLeader();
        // }
        // sortTeam(this->members);
        Character* victim = nullptr;
        victim = closest(enemyTeam); // find the close enemy to the leader
        if (victim && captin->isAlive()) {
            for (Character* attacker : members) {
                if (attacker->isAlive() && victim->isAlive()) { // when the attacker & victim is alive -> the attacker attack the victim
                    attacker->attack(victim);  
                }
                else if(attacker->isAlive() && !victim->isAlive()){ // when the attacker is alive & victim is not alive -> select another victim that close to the leader
                    if(!enemyTeam->stillAlive()){ // if there is no teammate alive break
                        return;
                    }
                    victim = closest(enemyTeam);
                    attacker->attack(victim);
                }
            }
        }
    }

    int Team::stillAlive() const{ // return the number of the members that is alive
        int aliveCount = 0;
        for (Character* member : members) {
            if (member->isAlive()) { // if member is alive we increase aliveCount by 1
                aliveCount++;
            }
        }
        return aliveCount;
    }

    void Team::print() const{ // print the details of all the members in the team
        // sortTeam(this->members);
        string leaderName = this->captin->getName();
        cout << "Team " << leaderName << " has " << to_string(this->stillAlive()) << " members alive and " << to_string(((int)members.size()-stillAlive()))<<" members died are:\n" << endl;
        for (Character* member : this->members) {
            cout << "\t" << member->print() << endl;
        }
        cout << "End of Team members" << endl << endl;
    }

    // =================================== End Team Functions ===================================


    // =================================== Desctructor ===================================
    Team::~Team(){
        for (auto& member : members) {
            delete member;
        }
    }

    // =================================== End Desctructor ===================================
}