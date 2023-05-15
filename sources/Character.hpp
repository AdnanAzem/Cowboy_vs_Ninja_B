#pragma once
#include "Point.hpp"

namespace ariel{
    class Character{

        private:
            Point location;
            string name;
            int health;
            bool isMember;
            // bool isCaptin;

        public:
            Character();
            // Character(string , const Point&);
            Character(string, const Point&, int);

            // Setters
            void setHealth(int);
            void setLocation(const Point& loc){location = loc;}
            void setIsMember(bool flag){isMember = flag;}
            // void setCaptin(bool flag){isCaptin = flag;}

            // Getters
            string getName()const; // return the name of the character
            int getHealth()const; // return the health of the character
            Point getLocation() const; // return the location of the character
            bool getIsMember() {return isMember;}
            // bool getIsCaptin() const{return isCaptin;} // return if the character is captain


            bool isAlive() const; // return if the character is alive -- health > 0
            // double distance (const Point&); // return the distance between 2 characters
            double distance (const Character*) const;
            void hit(int); // reduce the health of the character
            virtual string print() const = 0; // print: name, health, location, isAlive() --> no print healt & (name), before the name print N | C
            virtual ~Character();
            virtual void attack(Character*) = 0;
    };
}
