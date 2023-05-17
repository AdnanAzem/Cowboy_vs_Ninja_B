// like team but we implement the best order

#include "SmartTeam.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace ariel{
    SmartTeam::SmartTeam(Character* leader):Team(leader){

    }


    Character* SmartTeam::chooseVictim(Character* attacker, Team* enemyTeam) {
        Character* victim = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character* enemyFighter : enemyTeam->getTeam()) {
            if (enemyFighter->isAlive()) {
                double distance = attacker->distance(enemyFighter);
                if (distance < minDistance) {
                    victim = enemyFighter;
                    minDistance = distance;
                }
            }
        }
        return victim;
    }

    void SmartTeam::add(Character* newMember){ // add member to the team
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

    void SmartTeam::attack(Team* enemyTeam) {
        if(enemyTeam == nullptr){ // check if we receive a null
            throw std::invalid_argument("Enemy Team is Null");
        }
        if(!stillAlive()){ // check if the team is not alive
            throw std::runtime_error("The Team is Dead");
        }
        if(!enemyTeam->stillAlive()){ // check if the enemy team is not alive
            throw std::runtime_error("Enemy Team is Dead");
        }
        if (!getLeader()->isAlive()) { // check if the leader is not alive
                this->changeLeader();
        }
        // Determine the enemy leader
        Character* enemyLeader = enemyTeam->getLeader();

        // Sort the fighters in both teams based on their proximity to the enemy leader
        std::sort(getTeam().begin(), getTeam().end(), [&](Character* a, Character* b) {
            return a->distance(enemyLeader) < b->distance(enemyLeader);
        });

        std::sort(enemyTeam->getTeam().begin(), enemyTeam->getTeam().end(), [&](Character* a, Character* b) {
            return a->distance(enemyLeader) < b->distance(enemyLeader);
        });

        // Attack the enemy team
        for (Character* attacker : getTeam()) {
            if (!attacker->isAlive()) {
                continue; // Skip to the next fighter if attacker is dead
            }

            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)) {
                // Check if cowboy has bullets
                if (cowboy->hasboolets()) {
                    Character* closestEnemy = nullptr;

                    // Find the closest alive enemy fighter to the cowboy
                    closestEnemy = chooseVictim(cowboy,enemyTeam);

                    // Shoot the closest enemy fighter
                    if (closestEnemy ) {
                        cowboy->shoot(closestEnemy);
                    }
                } 
                else {
                    cowboy->reload();
                }
            } 
            else if (Ninja* ninja = dynamic_cast<Ninja*>(attacker)) {
                // Check if ninja is within attack range of enemy leader
                if (ninja->distance(enemyLeader) < 1) {
                    ninja->slash(enemyLeader);
                } 
                else {
                    // Attack the closest enemy fighters within range
                    Character* closestEnemy = nullptr;
                    closestEnemy = chooseVictim(ninja, enemyTeam);
                    double distance = ninja->distance(closestEnemy);
                    if(distance < 1){
                        ninja->attack(closestEnemy);
                    }
                    else{
                        // Move towards the enemy leader
                        ninja->move(enemyLeader); 
                    }
                }
            }
        }
    }
}