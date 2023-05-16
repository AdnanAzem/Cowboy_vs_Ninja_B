#include "Team.hpp"
#include <typeinfo>
namespace ariel{

    Team::Team(){
        
        
    }

    Team::Team(Character* leader):captin(leader){
        this->add(captin);
        captin->setIsMember(true);
    }

    void Team::add(Character* newMember){
        if(newMember == nullptr){
            throw runtime_error("Null Character!!!");
        }
        if (newMember->getIsMember()) {
            throw runtime_error("Already in Team!!!");
        }
        if (this->members.size() >= 10) {
            throw runtime_error("Team is Full!!!");
        } 
        else {
            this->members.push_back(newMember);
            newMember->setIsMember(true);
            sortTeam(this->members);
        }
    }

    vector<Character *> Team::sortTeam(vector<Character *> list) {
        vector<Character *> newList;
        //first cowboys:
        for (Character* c : list) {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(c)) {
                newList.push_back(cowboy);
            }
        }
        //second ninjas:
        for (Character* c : list) {
            if (Ninja* ninja = dynamic_cast<Ninja*>(c)) {
                newList.push_back(ninja);
            }
        }
        return newList;
    }

    void Team::changeLeader(){
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

    void Team::changeLeader(Team* list){
        double minDistance = std::numeric_limits<double>::max();
        Character* closestFighter = nullptr;
        for (Character* fighter : list->members) {
            if (fighter->isAlive()) {
                double distance = fighter->distance(list->captin);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestFighter = fighter;
                }
            }
        }
        list->captin = closestFighter;
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
        if(!enemyTeam->captin->isAlive()){ // check if the enemy leader is not alive
            enemyTeam->changeLeader();
        }
        
        Character* victim = nullptr;
        double minDistance = std::numeric_limits<double>::max();
        for (Character* enemyFighter : enemyTeam->members) {
            if (enemyFighter->isAlive()) {
                double distance = captin->distance(enemyFighter);
                if (distance < minDistance) {
                    minDistance = distance;
                    victim = enemyFighter;
                }
            }
        }
        // sorted the team cowboy first then ninja
        // vector<Character *> sortedTeam = sortTeam(this->members);
        if (victim && captin->isAlive()) {
            for (Character* attacker : members) {
                if (attacker->isAlive() && victim->isAlive()) {
                    attacker->attack(victim);  
                }
                else if(attacker->isAlive() && !victim->isAlive()){
                    if(!enemyTeam->stillAlive()){
                        return;
                    }
                    victim = nullptr;
                    minDistance = std::numeric_limits<double>::max();
                    for (Character* enemyFighter : enemyTeam->members) {
                        if (enemyFighter->isAlive()) {
                            double distance = captin->distance(enemyFighter);
                            if (distance < minDistance) {
                                minDistance = distance;
                                victim = enemyFighter;
                            }
                        }
                    }
                    attacker->attack(victim);
                }
            }

        }


    }


    int Team::stillAlive(){
        int aliveCount = 0;
        for (Character* member : members) {
            if (member->isAlive()) {
                aliveCount++;
            }
        }
        return aliveCount;
    }

    void Team::print(){
        for (Character* member : members) {
            member->print();
        }
    }

    Team::~Team(){
        for (auto& member : members) {
            delete member;
        }
    }
}