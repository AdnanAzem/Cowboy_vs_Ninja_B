#include "Cowboy.hpp"

namespace ariel{
    // Cowboy::Cowboy(string name, const Point& location):Character(name,location),bullets(6){
    //     this->setHealth(110);
    // }

    // =================================== Constructor ===================================

    Cowboy::Cowboy(string name, const Point& location):Character(name,location,110), bullets(6){

    }
    // =================================== End Constructor ===================================


    // =================================== Cowboy Functions ===================================
    
    void Cowboy::shoot(Character* enemy){
        if(enemy == NULL){ // throw error when the enemy is null
            throw std::runtime_error("Null Pointer!!!");
        }
        else if(!this->isAlive()){// throw error when the cowboy is dead
            throw std::runtime_error("You are dead!!!");
        }
        else if(this == enemy){ // throw error when the input is us
            throw std::runtime_error("You can't shoot yourself");
        }
        else if(!enemy->isAlive()){ // throw error when the enemy is dead
            throw std::runtime_error("Enemy is dead");
        }
        else if(enemy->isAlive() && hasboolets()){ // hit the enemy if he i alive and we have bullets
            enemy->hit(10);
            bullets--;
        }
        else if(!hasboolets()){ // relaod when we don't have bullets
            reload();
        }
    }

    bool Cowboy::hasboolets(){ // check if the cowboy has bullets
        return this->bullets > 0;
    }

    void Cowboy::reload(){ // reload 
        if(this->isAlive()){
                this->bullets = 6;
        }
        else{
            throw std::runtime_error("You are dead!!!");
        }
    }

    string Cowboy::print() const { // print the details of the cowboy
        if (!isAlive()) {
            return "=C= {" + this->getName() + "} " + "died at " + this->getLocation().print() + "\n";
        } else {
            return "=C= " + this->getName() + " has (" + to_string(this->getHealth()) + " HP, " + to_string(bullets) + " bullets) at " + this->getLocation().print() + "\n";
        }
    }

    void Cowboy::attack(Character* enemy){
        this->shoot(enemy);
    }

    // =================================== End Cowboy Functions ===================================

}