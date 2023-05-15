#include "doctest.h"
#include <iostream>	
#include <stdexcept>
#include <cassert>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
using namespace ariel;

TEST_CASE("Check Young Ninja Stats"){
    Point p(2,2);
    YoungNinja *ninja = new YoungNinja("sakura",Point(2,2));
    // The speed of Young ninja should be 14.
    CHECK(ninja->getSpeed() == 14);
    // The health of Young ninja should be 100.
    CHECK(ninja->getHealth() == 100);
    // check if the Young Ninja is alive should return true.
    CHECK(ninja->isAlive());
    CHECK(ninja->getName() == "sakura");

}

TEST_CASE("Check Trained Ninja Stats"){
    Point p(2,2);
    TrainedNinja *ninja = new TrainedNinja("sakura",Point(2,2));
    // The speed of Trained ninja should be 12.
    CHECK(ninja->getSpeed() == 12);
    // The health of Trained ninja should be 120.
    CHECK(ninja->getHealth() == 120);
    // check if the Trained Ninja is alive should return true.
    CHECK(ninja->isAlive());
    CHECK(ninja->getName() == "sakura");
}

TEST_CASE("Check Old Ninja Stats"){
    Point p(2,2);
    OldNinja *ninja = new OldNinja("sakura",Point(2,2));
    // The speed of Old ninja should be 8.
    CHECK(ninja->getSpeed() == 8);
    // The health of Old ninja should be 150.
    CHECK(ninja->getHealth() == 150);    
    // check if the Old Ninja is alive should return true.
    CHECK(ninja->isAlive());
    CHECK(ninja->getName() == "sakura");

}

TEST_CASE("Check Cowboy Stats"){
    Cowboy *cowboy = new Cowboy("yuri", Point(1,3));
    // The health of Cowboy should be 110.
    CHECK(cowboy->getHealth() == 110);
    // The number of boolets should be 6.
    CHECK(cowboy->getAmountOfBalls() == 6);
    // check if the cowboy is alive should return true.
    CHECK(cowboy->isAlive());
}

TEST_CASE("Cowbow coudn't hit himself"){
    Cowboy *cowboy = new Cowboy("yuri", Point(1,3));
    // shoot himself should throw error.
    CHECK_THROWS(cowboy->shoot(cowboy));
}

TEST_CASE("Ninja speed can't be negative"){
    Ninja *ninja = new Ninja("kakashi", Point(45,98));
    // throw error if the speed is negative
    CHECK_GE(ninja->getSpeed(), 0);
}

TEST_CASE("Cowboy vs Ninja"){
    Ninja *ninja = new Ninja("madara", Point(1,2));
    Cowboy *cowboy = new Cowboy("yuri", Point(1,3));
    // check if the ninja is alive or not shouldn't throw error
    CHECK_NOTHROW(ninja->isAlive());
    // check if the cowboy is alive or not shouldn't throw error
    CHECK_NOTHROW(cowboy->isAlive());
    if(ninja->isAlive() && cowboy->isAlive()){
        // ninja should slash cowboy
        CHECK_NOTHROW(ninja->slash(cowboy));
        // cowboy should shoot ninja
        CHECK_NOTHROW(cowboy->shoot(ninja));
        // ninja should move to cowboy
        CHECK_NOTHROW(ninja->move(cowboy));
    }
    else if(!ninja->isAlive()){ // ninja dead
        // ninja can't slash when he dead so throws exception
        CHECK_THROWS(ninja->slash(cowboy));
        // cowboy can't shoot who dead so throws exception
        CHECK_THROWS(cowboy->shoot(ninja));
        // ninja can't move when he dead so throws exception
        CHECK_THROWS(ninja->move(cowboy));
    }
    else{ // cowboy dead
        // ninja can't slash who dead so throws exception
        CHECK_THROWS(ninja->slash(cowboy));
        // cowboy can't shoot when he dead so throws exception
        CHECK_THROWS(cowboy->shoot(ninja));
        // ninja can move to who dead so don't throw exception
        CHECK_NOTHROW(ninja->move(cowboy));
    }


}

TEST_CASE("Throwing errors when the cowboy is dead and use functions"){
    Cowboy *cowboy = new Cowboy("Tom", Point(0,0));
    if(!cowboy->isAlive()){
        // can't reload the weapon
        CHECK_THROWS(cowboy->reload());
        // can't shoot
        CHECK_THROWS(cowboy->shoot(new Ninja("sakura",Point(4,2))));
        // can't hit
        CHECK_THROWS(cowboy->hit(4));
    }
}

TEST_CASE("Throwing errors when the ninja is dead and use functions"){
    Ninja *ninja = new Ninja("Sakura", Point(0,0));
    if(!ninja->isAlive()){
        // can't move
        CHECK_THROWS(ninja->move(new Cowboy("Tom",Point(9,9))));
        // can't slash
        CHECK_THROWS(ninja->slash(new Cowboy("Tom",Point(9,9))));
        // can't hit
        CHECK_THROWS(ninja->hit(7));
    }
}

TEST_CASE("Throwing errors when the young ninja is dead and use functions"){
    YoungNinja *ninja = new YoungNinja("Sakura", Point(0,0));
    if(!ninja->isAlive()){
        // can't move
        CHECK_THROWS(ninja->move(new Cowboy("Tom",Point(9,9))));
        // can't slash
        CHECK_THROWS(ninja->slash(new Cowboy("Tom",Point(9,9))));
        // can't hit
        CHECK_THROWS(ninja->hit(7));
    }
}

TEST_CASE("Throwing errors when the trained ninja is dead and use functions"){
    TrainedNinja *ninja = new TrainedNinja("Sakura", Point(0,0));
    if(!ninja->isAlive()){
        // can't move
        CHECK_THROWS(ninja->move(new Cowboy("Tom",Point(9,9))));
        // can't slash
        CHECK_THROWS(ninja->slash(new Cowboy("Tom",Point(9,9))));
        // can't hit
        CHECK_THROWS(ninja->hit(7));
    }
}

TEST_CASE("Throwing errors when the old ninja is dead and use functions"){
    OldNinja *ninja = new OldNinja("Sakura", Point(0,0));
    if(!ninja->isAlive()){
        // can't move
        CHECK_THROWS(ninja->move(new Cowboy("Tom",Point(9,9))));
        // can't slash
        CHECK_THROWS(ninja->slash(new Cowboy("Tom",Point(9,9))));
        // can't hit
        CHECK_THROWS(ninja->hit(7));
    }
}

TEST_CASE("Adding Characters to the team"){
    Point p(2,2);
    Cowboy *c1 = new Cowboy("Tom", p);
    YoungNinja *c2 = new YoungNinja("Tom", p);
    TrainedNinja *c3 = new TrainedNinja("Tom", p);
    OldNinja *c4 = new OldNinja("Tom", p);
    Ninja *c5 = new Ninja("Tom", p);
    Team team_A(c1); 
    // adding to team should not throw error if the size of team less than 10.
    CHECK_NOTHROW(team_A.add(c2));
    CHECK_NOTHROW(team_A.add(c3));
    CHECK_NOTHROW(team_A.add(c4));
    CHECK_NOTHROW(team_A.add(c5));

    CHECK(typeid(&team_A.getTeam()[0]) == typeid(Cowboy));
    CHECK(typeid(&team_A.getTeam()[1]) == typeid(YoungNinja));
    CHECK(typeid(&team_A.getTeam()[2]) == typeid(TrainedNinja));
    CHECK(typeid(&team_A.getTeam()[3]) == typeid(OldNinja));
    CHECK(typeid(&team_A.getTeam()[4]) == typeid(Ninja));
}

TEST_CASE("Adding Character to Team that is full should throw exception"){
        Cowboy *c1 = new Cowboy("Tom", Point(0,0));
        Team team(c1); 
        // fill the team to be there 10 characters
        for (size_t i = 1; i < 9; i++)
        {
            Cowboy *c = new Cowboy(to_string(i), Point(0,0));
            CHECK_NOTHROW(team.add(c));
        }
        // adding one more character to team with 10 should throw error
        CHECK_THROWS(team.add(new Cowboy("kuro",Point(0,0))));    
}

TEST_CASE("Adding Character to Team2 that is full should throw exception"){
        Cowboy *c1 = new Cowboy("Tom", Point(0,0));
        Team2 team(c1); 
        // fill the team to be there 10 characters
        for (size_t i = 1; i < 9; i++)
        {
            Cowboy *c = new Cowboy(to_string(i), Point(0,0));
            CHECK_NOTHROW(team.add(c));
        }
        // adding one more character to team with 10 should throw error
        CHECK_THROWS(team.add(new Cowboy("kuro",Point(0,0))));    
}

TEST_CASE("Adding Character to SmartTeam that is full should throw exception"){
        Cowboy *c1 = new Cowboy("Tom", Point(0,0));
        SmartTeam team(c1); 
        // fill the team to be there 10 characters
        for (size_t i = 1; i < 9; i++)
        {
            Cowboy *c = new Cowboy(to_string(i), Point(0,0));
            CHECK_NOTHROW(team.add(c));
        }
        // adding one more character to team with 10 should throw error
        CHECK_THROWS(team.add(new Cowboy("kuro",Point(0,0))));    
}

TEST_CASE("Team vs Team"){
    Team team_A(new Cowboy("Tom", Point(1,19))); 
    Team team_B(new YoungNinja("sushi", Point(54,-22))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }

    for (size_t i = 1; i < 9; i++)
    {
        YoungNinja *n = new YoungNinja(to_string(i), Point(54,-22));
        CHECK_NOTHROW(team_A.add(n));
    }
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_A.attack(&team_B));
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_B.attack(&team_A)); 
}

TEST_CASE("Team vs Team2"){
    Team team_A(new Cowboy("Tom", Point(1,19))); 
    Team2 team_B(new YoungNinja("sushi", Point(54,-22))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }

    for (size_t i = 1; i < 9; i++)
    {
        YoungNinja *n = new YoungNinja(to_string(i), Point(54,-22));
        CHECK_NOTHROW(team_A.add(n));
    }
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_A.attack(&team_B));
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_B.attack(&team_A)); 
}

TEST_CASE("Team vs SmartTeam"){
    Team team_A(new Cowboy("Tom", Point(1,19))); 
    SmartTeam team_B(new YoungNinja("sushi", Point(54,-22))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }

    for (size_t i = 1; i < 9; i++)
    {
        YoungNinja *n = new YoungNinja(to_string(i), Point(54,-22));
        CHECK_NOTHROW(team_A.add(n));
    }
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_A.attack(&team_B));
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_B.attack(&team_A)); 
}

TEST_CASE("Team2 vs Team2"){
    Team2 team_A(new Cowboy("Tom", Point(1,19))); 
    Team2 team_B(new YoungNinja("sushi", Point(54,-22))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }

    for (size_t i = 1; i < 9; i++)
    {
        YoungNinja *n = new YoungNinja(to_string(i), Point(54,-22));
        CHECK_NOTHROW(team_A.add(n));
    }
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_A.attack(&team_B));
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_B.attack(&team_A)); 
}

TEST_CASE("Team2 vs SmartTeam"){
    Team2 team_A(new Cowboy("Tom", Point(1,19))); 
    SmartTeam team_B(new YoungNinja("sushi", Point(54,-22))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }

    for (size_t i = 1; i < 9; i++)
    {
        YoungNinja *n = new YoungNinja(to_string(i), Point(54,-22));
        CHECK_NOTHROW(team_A.add(n));
    }
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_A.attack(&team_B));
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_B.attack(&team_A)); 
}

TEST_CASE("SmartTeam vs SmartTeam"){
    SmartTeam team_A(new Cowboy("Tom", Point(1,19))); 
    SmartTeam team_B(new YoungNinja("sushi", Point(54,-22))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }

    for (size_t i = 1; i < 9; i++)
    {
        YoungNinja *n = new YoungNinja(to_string(i), Point(54,-22));
        CHECK_NOTHROW(team_A.add(n));
    }
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_A.attack(&team_B));
    // when team attacks himself should not throw error
    CHECK_NOTHROW(team_B.attack(&team_A)); 
}

TEST_CASE("Team can't attack himself"){
    Team team_A(new Cowboy("Tom", Point(1,19))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }
    // when team attacks himself should throw error
    CHECK_THROWS(team_A.attack(&team_A));
}

TEST_CASE("Team2 can't attack himself"){
    Team2 team_A(new Cowboy("Tom", Point(1,19))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }
    // when team attacks himself should throw error
    CHECK_THROWS(team_A.attack(&team_A));
}

TEST_CASE("SmartTeam can't attack himself"){
    SmartTeam team_A(new Cowboy("Tom", Point(1,19))); 
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }
    // when team attacks himself should throw error
    CHECK_THROWS(team_A.attack(&team_A));
}

TEST_CASE("Team can't attack team that is not created"){
    Team team_A(new Cowboy("Tom", Point(1,19))); 
    Team team_B;
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }
    // when team attacks himself should throw error
    CHECK_THROWS(team_A.attack(&team_B));
}

TEST_CASE("Team2 can't attack team that is not created"){
    Team2 team_A(new Cowboy("Tom", Point(1,19))); 
    Team team_B;
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }
    // when team attacks himself should throw error
    CHECK_THROWS(team_A.attack(&team_B));
}

TEST_CASE("SmartTeam can't attack team that is not created"){
    SmartTeam team_A(new Cowboy("Tom", Point(1,19))); 
    Team team_B;
    for (size_t i = 1; i < 9; i++)
    {
        Cowboy *c = new Cowboy(to_string(i), Point(1,19));
        CHECK_NOTHROW(team_A.add(c));
    }
    // when team attacks himself should throw error
    CHECK_THROWS(team_A.attack(&team_B));
}





