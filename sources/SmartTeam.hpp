#pragma once
#include "Team.hpp"

namespace ariel{
    class SmartTeam : public Team{
        private:

        public:
        SmartTeam(Character*);
        void attack(Team* enemyTeam) override; // override attack function
        void add(Character* newMember) override; // override add function

        // The chooseVictim() function selects the victim for the attacker based on their proximity
        Character* chooseVictim(Character* , Team* );
        
    };
}