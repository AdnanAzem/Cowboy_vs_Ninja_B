#include "Character.hpp"

namespace ariel{

    // =================================== Constructors ===================================
    // Character::Character(){

    // }

    Character::Character(string name, const Point& location, int hp): name(name), location(location), health(hp),isMember(false){

    }
    // =================================== End Constructors ===================================

    // =================================== Character Functions ===================================
    bool Character::isAlive() const{ // check if the character is alive
        return health > 0;
    }

    double Character::distance (const Character* other) const{ // return the distance from other character
        return this->location.distance(other->location);
    }

    void Character::hit(int damage){ // reduce the health
        if(damage < 0){
            throw invalid_argument("Damage can't be negative");
        }
        this->health -= damage;
        if(this->health < 0) this->health = 0;
    }

    // string Character::print() const{
    //     return name + " (" + to_string(health) + " HP) at " + location.toString();

    //     // if(this->isAlive()){
    //     //     return "Name: " + this->getName() + ", Health: " + to_string(this->getHealth()) + ", Location: " + this->getLocation().toString();
    //     // }
    //     // else{
    //     //     return "{" + this->getName() + "}";
    //     // }
        
    // }
    // =================================== End Character Functions ===================================


    // =================================== Descructor ===================================
    Character::~Character(){
        
    }
    // =================================== End Descructor ===================================
}