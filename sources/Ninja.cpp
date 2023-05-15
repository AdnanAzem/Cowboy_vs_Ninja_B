#include "Ninja.hpp"

namespace ariel
{

    // Ninja::Ninja(string name, const Point& location):Character(name,location){

    // }

    // Ninja::Ninja(string name, const Point& location, int speed):Character(name,location){
    //     this->speed = speed;
    // }

    Ninja::Ninja(string name, const Point& location, int hp, int speed):Character(name,location,hp),speed(speed){

    }
    
    

    void Ninja::move(Character* enemy){
        double d = this->getLocation().distance(enemy->getLocation());
        if (d > speed) {
            double ratio = speed / d;
            double newX = this->getLocation().get_x() + (enemy->getLocation().get_x() - this->getLocation().get_x()) * ratio;
            double newY = this->getLocation().get_y() + (enemy->getLocation().get_y() - this->getLocation().get_y()) * ratio;
            // location = Point(newX, newY);
            this->setLocation(Point(newX, newY));
        } else {
            // location = c->getLocation();
            this->setLocation(enemy->getLocation());
        }
        // if (enemy != nullptr && enemy->isAlive()) {
        // double dist = this->getLocation().distance(enemy->getLocation());
        // if (dist >= speed) {
        //     Point direction = this->getLocation().direction(enemy->getLocation());
        //     Point newLocation = this->getLocation().move(direction, speed);
        //     this->setLocation(newLocation);
        //     }
        // }
        // this->getLocation().distance(enemy->getLocation());

    }

    void Ninja::slash(Character* enemy){
        if(enemy == nullptr){
            throw std::runtime_error("Null Pointer!!!");
        }
        else if(!this->isAlive() || !enemy->isAlive()){
            throw std::runtime_error("Character are dead!!!");
        }
        else if(this == enemy){
            throw std::runtime_error("You can't shoot yourself");
        }
        // else if(!enemy->isAlive()){
        //     throw std::runtime_error("N - Enemy is dead!!!");
        // }
        else{
            double dist = this->getLocation().distance(enemy->getLocation());
            if (isAlive() && dist < 1) {
                enemy->hit(40);
                isAttack = true;
            }
            else if(dist >= 1){
                isAttack = false;
                // move(enemy);
            }
        }

        // if (isAlive() && enemy != nullptr && enemy->isAlive()) {
        //     double dist = this->getLocation().distance(enemy->getLocation());
        //     if (dist < 1.0) {
        //         enemy->hit(40);
        //     }
        // }
    }

    int Ninja::getSpeed(){
        return this->speed;
    }

    void Ninja::setSpeed(int speed){
        this->speed = speed;
    }

    // string Character::print() {
    // if(this->isAlive()){
    //         return "N ==>> Name: " + this->getName() + ", Health: " + to_string(this->getHealth()) + ", Location: " + this->getLocation().toString();
    //     }
    //     else{
    //         return "{" + this->getName() + "}";
    //     }
    // }

    string Ninja::print() const{
        // return "N " + this->getName() + " (" + to_string(this->getHealth()) + ") " + this->getLocation().toString() ;
        // cout << "N " << name << " (" << hitPoints << ") " << location << endl;
            if (!isAlive()) {
        return "--N--\nname: (" + this->getName() + ")\npos: " + this->getLocation().toString() + "\nSpeed: " +
               to_string(speed) + "\n";
    } else {
        return "--N--\nname: " + this->getName() + "\nhitPoint: " + to_string(this->getHealth()) + "\npos: " + this->getLocation().toString() + "\nSpeed: " +
               to_string(speed) + "\n";
    }
    }


    
} 
