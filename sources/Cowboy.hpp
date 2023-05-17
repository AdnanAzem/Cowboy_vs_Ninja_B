#pragma once
#include "Character.hpp"
#include <iostream>
using namespace std;
namespace ariel{

    class Cowboy : public Character{
        private:
            // health = 110, amount_of_balls = 6
            int bullets;

        public:
            Cowboy(string name, const Point& location):Character(name,location,110), bullets(6){}
            // Cowboy(string , const Point&);
            // Cowboy(string , const Point&, int);
            void shoot(Character*); // reduce 10 health from other character
            bool hasboolets(); // return if the cowboy have boolets in the weapon
            void reload(); // reload balls to the weapon 
            int getAmountOfBalls() const {return this->bullets;} // return amount_of_balls
            string print() const override; // print the stats
            void attack(Character* enemy) override; // attack the enemy
    };

}