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
            int teamSize;
            int teamSizeMax;

        public:
            Team();
            Team(Character*);

            //Setters
            void setTeam(vector<Character*> newTeam){this->members = newTeam;}
            void setLeader(Character* newLeader){this->captin = newLeader;}

            //getters
            vector<Character*> getTeam(){return this->members;}
            Character* getLeader(){return this->captin;}

            void add(Character*); // add character to the team
            virtual void attack(Team*); // attack other team -- check if the leader is alive else pick another leader(by smallest distance)
            int stillAlive(); // return the number of the members that still alive in the team
            void print(); // print the details of the members in the team
            ~Team(); // free the memory
            vector<Character*> sortTeam(vector<Character*> list);
            void changeLeader();
            void changeLeader(Team*);

    };

}
