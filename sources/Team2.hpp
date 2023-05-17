#pragma once
#include "Team.hpp"

namespace ariel{
    class Team2 : public Team {
        private:

        public:
        Team2(Character*);
        void attack(Team* enemyTeam) override; // override attack function
        void add(Character* newMember) override; // override add function
        // ~Team();
    };
}