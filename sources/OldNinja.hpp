#pragma once
#include "Ninja.hpp"

namespace ariel{
    class OldNinja : public Ninja{
        private:
            // health = 150, speed = 8

        public:
            OldNinja(string,const Point&);
            
            // ~OldNinja();
            // virtual string print() const;

    };
}