#pragma once
#include "Ninja.hpp"

namespace ariel{
    class YoungNinja : public Ninja{
        private:
            // health = 100, speed = 14

        public:
            // YoungNinja(string , const Point&);
            YoungNinja(string name, const Point& location):Ninja(name, location, 100, 14){}

    };
}