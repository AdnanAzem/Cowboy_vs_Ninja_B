#pragma once
#include "Point.hpp"

namespace ariel{
    class Character{

        private:
            Point location;
            string name;
            int health;
            bool isMember;

        public:
            // Character(string, const Point&, int);
            Character(string name, const Point& location, int hp): name(name), location(location), health(hp),isMember(false){}

            // we must need to have this constructors to pass make tidy
            Character() = delete; 
            Character(const Character &) = delete;
            Character& operator =(Character const&) = delete;
            Character(Character&&) = delete;
            Character& operator=(Character&&) = delete;

            // Setters
            void setHealth(int _hp){health = _hp;}
            void setLocation(const Point& loc){location = loc;}
            void setIsMember(bool flag){isMember = flag;}

            // Getters
            string getName()const{return name;} // return the name of the character
            int getHealth()const{return health;} // return the health of the character
            Point getLocation() const{return location;} // return the location of the character
            bool getIsMember() const{return isMember;} // return if the character is already in team

            bool isAlive() const; // return if the character is alive -- health > 0
            double distance (const Character*) const; // return the distance between 2 characters
            void hit(int); // reduce the health of the character
            virtual string print() const = 0; // print: name, health, location, isAlive() --> no print healt & (name), before the name print N | C
            virtual ~Character(); // descructor
            virtual void attack(Character*) = 0; // attack the enemy
    };
}
