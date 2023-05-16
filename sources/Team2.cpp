// like Team but the order by the addition to the team

#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
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