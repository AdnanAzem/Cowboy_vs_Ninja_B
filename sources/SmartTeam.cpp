// like team but we implement the best order

#include "SmartTeam.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

namespace ariel{
    SmartTeam::SmartTeam(Character* leader):Team(leader){

    }

    double SmartTeam::calculatePotentialDamage(Character* attacker, Team* enemyTeam) {
        double potentialDamage = 0.0;

        Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);
        if (cowboy) {
            if (cowboy->hasboolets()) {
                // Calculate potential damage for Cowboys with bullets
                for (Character* enemyFighter : enemyTeam->getTeam()) {
                    if (enemyFighter->isAlive()) {
                        //double distance = attacker->distance(enemyFighter);
                        //if (distance <= cowboy->getEffectiveRange()) {
                            potentialDamage += 10; //cowboy->getDamage();
                        //}
                    }
                }
            } 
            else {
                // Calculate potential damage for Cowboys without bullets
                // potentialDamage += cowboy->getReloadSpeed();
                cowboy->reload();
            }
        } else {
            Ninja* ninja = dynamic_cast<Ninja*>(attacker);
            if (ninja) {
                // Calculate potential damage for Ninjas
                for (Character* enemyFighter : enemyTeam->getTeam()) {
                    if (enemyFighter->isAlive()) {
                        double distance = attacker->distance(enemyFighter);
                        if (distance <= 1) {
                            potentialDamage += 40; // ninja->getDamage();
                        }
                    }
                }
            }
        }
        return potentialDamage;
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

    void SmartTeam::attack(Team* enemyTeam) {
        if (!getLeader()->isAlive()) {
            // Choose a new leader from the living characters closest to the dead leader
            changeLeader();
            // double minDistance = std::numeric_limits<double>::max();
            // for (Character* fighter : getTeam()) {
            //     if (fighter->isAlive()) {
            //         double distance = getLeader()->distance(fighter);
            //         if (distance < minDistance) {
            //             setLeader(fighter);
            //             minDistance = distance;
            //         }
            //     }
            // }
        }

        while (!getTeam().empty() && !enemyTeam->getTeam().empty()) {
            // Choose the character with the maximum potential damage based on the situation
            Character* attacker = nullptr;
            double maxPotentialDamage = 0.0;

            for (Character* fighter : getTeam()) {
                if (fighter->isAlive()) {
                    double potentialDamage = calculatePotentialDamage(fighter, enemyTeam);
                    if (potentialDamage > maxPotentialDamage) {
                        attacker = fighter;
                        maxPotentialDamage = potentialDamage;
                    }
                }
            }

            if (attacker) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);
                if (cowboy && cowboy->hasboolets()) {
                    Character* victim = chooseVictim(attacker, enemyTeam);
                    if (victim) {
                        cowboy->shoot(victim);
                        if (!victim->isAlive()) {
                            // Remove the dead victim from the enemy team
                            auto it = std::find(enemyTeam->getTeam().begin(), enemyTeam->getTeam().end(), victim);
                            if (it != enemyTeam->getTeam().end()) {
                                enemyTeam->getTeam().erase(it);
                            }
                        }
                    }
                } else if (cowboy) {
                    cowboy->reload();
                } else {
                    Ninja* ninja = dynamic_cast<Ninja*>(attacker);
                    if (ninja) {
                        Character* victim = chooseVictim(attacker, enemyTeam);
                        if (victim) {
                            ninja->move(victim);
                            if (ninja->distance(victim) <= 1) {
                                ninja->slash(victim);
                                if (!victim->isAlive()) {
                                    // Remove the dead victim from the enemy team
                                    auto it = std::find(enemyTeam->getTeam().begin(), enemyTeam->getTeam().end(), victim);
                                    if (it != enemyTeam->getTeam().end()) {
                                        enemyTeam->getTeam().erase(it);
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                break;  // No living characters to attack
            }
        }
    }
}