#include "Character.hpp"

namespace ariel{
    Character::Character(){

    }



    Character::Character(string name, const Point& location, int hp): name(name), location(location), health(hp),isMember(false){

    }

    bool Character::isAlive() const{
        return health > 0;
    }

    // double Character::distance (const Point& target){
    //     return this->getLocation().distance(target);
    // }

    double Character::distance (const Character* other) const{
        return this->location.distance(other->location);
    }

    void Character::hit(int damage){
        if(damage < 0){
            throw invalid_argument("Damage can't be negative");
        }
        this->health -= damage;
        if(this->health < 0) this->health = 0;
    }

    string Character::getName( )const{
        return this->name;
    }

    Point Character::getLocation() const{
        return this->location;

    }

    string Character::print() const{
        return name + " (" + to_string(health) + " HP) at " + location.toString();

        // if(this->isAlive()){
        //     return "Name: " + this->getName() + ", Health: " + to_string(this->getHealth()) + ", Location: " + this->getLocation().toString();
        // }
        // else{
        //     return "{" + this->getName() + "}";
        // }
        
    }

    int Character::getHealth()const{
        return this->health;
    }

    void Character::setHealth(int health){
        this->health = health;
    }

    Character::~Character(){
        
    }
}