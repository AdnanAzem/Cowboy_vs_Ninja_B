#pragma once
#include <iostream>
#include <cmath>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>

using namespace std;
namespace ariel{
    class Team{
        private:
            // the order : 1) cowboy |-->>  2) ninja
            // max members in the team is 10
            vector<Character*> members;
            Character* captin;
            bool newTeam;

        public:
            // Constructors
            Team(Character*);
            
            // we must need to have this constructors to pass make tidy
            Team() = delete; // Added this little fella
            Team(const Team &) = delete;
            Team& operator =(Team const&) = delete;
            Team(Team&&) = delete;
            Team& operator=(Team&&) = delete;


            // Setters
            void setTeam(vector<Character*> newTeam){this->members = std::move(newTeam);}
            void setLeader(Character* newLeader){this->captin = newLeader;}

            // Getters
            vector<Character*> getTeam() {return this->members;}
            Character* getLeader(){return this->captin;}

            virtual void add(Character*); // add character to the team
            virtual void attack(Team*); // attack other team -- check if the leader is alive else pick another leader(by smallest distance)
            int stillAlive() const; // return the number of the members that still alive in the team
            virtual void print() const; // print the details of the members in the team
            vector<Character*> sortTeam(vector<Character*>) const; // sort the members first cowboys then ninjas
            void changeLeader(); // change the leader when dead
            Character* closest(Team *); // find the closest enemy from the leader

            virtual ~Team(); // free the memory

    };

}
