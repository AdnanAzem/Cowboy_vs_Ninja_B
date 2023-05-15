#include "Cowboy.hpp"

namespace ariel{
    // Cowboy::Cowboy(string name, const Point& location):Character(name,location),bullets(6){
    //     this->setHealth(110);
    // }

    Cowboy::Cowboy(string name, const Point& location):Character(name,location,110), bullets(6){

    }

    void Cowboy::shoot(Character* enemy){
        if(enemy == NULL){
            throw std::runtime_error("Null Pointer!!!");
        }
        else if(!this->isAlive()){
            throw std::runtime_error("You are dead!!!");
        }
        else if(this == enemy){
            throw std::runtime_error("You can't shoot yourself");
        }
        else if(!enemy->isAlive()){
            throw std::runtime_error("Enemy is dead");
        }
        else if(enemy->isAlive() && hasboolets()){
            enemy->hit(10);
            bullets--;
        }
        else if(!hasboolets()){
            reload();
        }
    }

    bool Cowboy::hasboolets(){
        return this->bullets > 0;
    }

    void Cowboy::reload(){
        if(this->isAlive()){
                this->bullets = 6;
        }
        else{
            throw std::runtime_error("You are dead!!!");
        }

    }

    Cowboy::~Cowboy(){
        
    }

    int Cowboy::getAmountOfBalls(){
        return this->bullets;
    }

    string Cowboy::print() const {
            if (!isAlive()) {
        return "--C--\nname: (" + this->getName()  + ")\npos: " + this->getLocation().toString() + "\nBullets: " +
               to_string(bullets) + "\n";
    } else {
        return "--C--\nname: " + this->getName()  + "\nhitPoint: " + to_string(this->getHealth()) + "\npos: " + this->getLocation().toString() + "\nBullets: " +
               to_string(bullets) + "\n";
    }
        // return "C " + this->getName() + " (" + to_string(this->getHealth()) + " HP, " + to_string(bullets) + " bullets) at " + this->getLocation().toString();
    }

    

}