#pragma once
#include "Team.hpp"

namespace ariel{
    class SmartTeam : public Team{
        private:

        public:
        SmartTeam(Character*);
        void attack(Team*);

        // The chooseVictim() function selects the victim for the attacker based on their proximity
        Character* chooseVictim(Character* , Team* );
        
        // The calculatePotentialDamage() function determines the potential damage that can be inflicted by an attacker 
        // based on their type (Cowboy or Ninja) and the distance to enemy fighters.
        double calculatePotentialDamage(Character* , Team* );
    };
}