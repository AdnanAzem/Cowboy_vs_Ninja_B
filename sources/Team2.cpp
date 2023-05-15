// like Team but the order by the addition to the team

#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
    }

    void Team2::attack(Team *enemyTeam)
    {
        if (enemyTeam == nullptr)
        {
            throw std::invalid_argument("Enemy Team is Null");
        }
        if(!stillAlive()){
            throw std::runtime_error("The Team is Dead");
        }
        if(!enemyTeam->stillAlive()){
            throw std::runtime_error("Enemy Team is Dead");
        }
        if (!getLeader()->isAlive())
        {
            changeLeader();
            // double minDistance = std::numeric_limits<double>::max();
            // Character *closestFighter = nullptr;
            // for (Character *fighter : getTeam())
            // {
            //     if (fighter->isAlive())
            //     {
            //         double distance = fighter->distance(getLeader());
            //         if (distance < minDistance)
            //         {
            //             minDistance = distance;
            //             closestFighter = fighter;
            //         }
            //     }
            // }
            // setLeader(closestFighter);
        }
        Character *victim = nullptr;
        double minDistance = std::numeric_limits<double>::max();
        for (Character *enemyFighter : enemyTeam->getTeam())
        {
            if (enemyFighter->isAlive())
            {
                double distance = getLeader()->distance(enemyFighter);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    victim = enemyFighter;
                }
            }
        }
        // if (victim && getLeader()->isAlive()) {
        for (Character *attacker : this->getTeam())
        {
            if (attacker->isAlive() && victim->isAlive())
            {
                attacker->attack(victim);
            }
            // }
            // victim = nullptr;
            // minDistance = std::numeric_limits<double>::max();
            // for (Character* enemyFighter : enemyTeam->getTeam()) {
            //     if (enemyFighter->isAlive()) {
            //         double distance = getLeader()->distance(enemyFighter);
            //         if (distance < minDistance) {
            //             minDistance = distance;
            //             victim = enemyFighter;
            //         }
            //     }
            // }
        }
    }
}