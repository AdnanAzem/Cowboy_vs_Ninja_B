// like Team but the order by the addition to the team

#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
    }

    void Team2::add(Character* newMember){ // add member to the team
        if(newMember == nullptr){ // throw error if the input is null
            throw runtime_error("Null Character!!!");
        }
        if (newMember->getIsMember()) { // throw error if the input is already in team
            throw runtime_error("Already in Team!!!");
        }
        if (this->getTeam().size() >= 10) { // throw error if size of team bigger or equal 10
            throw runtime_error("Team is Full!!!");
        } 
        else { // add member to the team 
            vector <Character*> newTeamMembers = getTeam(); // get the members of the team
            newTeamMembers.push_back(newMember); // add the new member to the team
            setTeam(newTeamMembers); // set the new team
            newMember->setIsMember(true); 
        }
    }

    void Team2::attack(Team *enemyTeam){
        
        if (enemyTeam == nullptr){ // check if we receive a null
            throw std::invalid_argument("Enemy Team is Null");
        }
        if(!stillAlive()){ // check if the team is not alive
            throw std::runtime_error("The Team is Dead");
        }
        if(!enemyTeam->stillAlive()){ // check if the enemy team is not alive
            throw std::runtime_error("Enemy Team is Dead");
        }
        if (!getLeader()->isAlive()){ // check if the leader is not alive
            changeLeader();
        }
        Character *victim = nullptr;
        victim = closest(enemyTeam); // find the close enemy to the leader
        // if (victim && getLeader()->isAlive()) {
        for (Character *attacker : this->getTeam()){
            if (attacker->isAlive() && victim->isAlive()){ // when the attacker & victim is alive -> the attacker attack the victim
                if(!enemyTeam->stillAlive()){ // if there is no teammate alive break
                    return;
                }
                victim = closest(enemyTeam);
                attacker->attack(victim);
            }
        }
    }
}