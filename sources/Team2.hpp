#pragma once
#include "Team.hpp"

namespace ariel{
    class Team2 : public Team {
        private:

        public:
        Team2(Character*);
        virtual void attack(Team*);
    };
}