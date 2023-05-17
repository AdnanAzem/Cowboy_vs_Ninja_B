#pragma once
#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;
        bool isAttack;
        
    public:
        // Ninja(string, const Point&);
        // Ninja(string, const Point&, int);
        Ninja(string , const Point& , int , int );

        void setSpeed(int _sp){speed = _sp;}
        int getSpeed() const{return speed;} // return the speed

        void move (Character*); // move to other character -- distance = speed of ninja
        void slash (Character*); // if the enemy is alive & distance < 1 reduce 13 health from the enemy
        string print() const override; // print the details
        void attack(Character* enemy) override; // attack the enemy
        
    };
      
} 


