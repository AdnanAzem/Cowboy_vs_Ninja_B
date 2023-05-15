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

        void setSpeed(int);

        void move (Character*); // move to other character -- distance = speed of ninja
        void slash (Character*); // if the enemy is alive & distance < 1 reduce 13 health from the enemy
        int getSpeed(); // return the speed
        // string print();
        virtual string print() const;
        virtual void attack(Character* enemy){
            this->slash(enemy);
            if(!isAttack){
                this->move(enemy);
            }

        }
        
    };
      
} 


