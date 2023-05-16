#pragma once
#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja : public Ninja{
        private:
            // health = 120, speed = 12

        public:
            TrainedNinja(string, const Point&);

    };
}