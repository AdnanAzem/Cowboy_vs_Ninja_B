#include "Ninja.hpp"

namespace ariel
{

    // =================================== Constructor ===================================
    // Ninja::Ninja(string name, const Point& location, int hp, int speed):Character(name,location,hp),speed(speed){

    // }
    // =================================== End Constructor ===================================

    // =================================== Ninja Functions ===================================
    void Ninja::move(Character* enemy){
        double d = this->getLocation().distance(enemy->getLocation());
        if (d > speed) {
            double ratio = speed / d;
            double newX = this->getLocation().get_x() + (enemy->getLocation().get_x() - this->getLocation().get_x()) * ratio;
            double newY = this->getLocation().get_y() + (enemy->getLocation().get_y() - this->getLocation().get_y()) * ratio;
            this->setLocation(Point(newX, newY));
        } else {
            this->setLocation(enemy->getLocation());
        }
    }

    void Ninja::slash(Character* enemy){ // slash the enemy
        if(enemy == nullptr){ // throw error when enemy is null
            throw std::runtime_error("Null Pointer!!!");
        }
        else if(!this->isAlive() || !enemy->isAlive()){ // throw error when the enemy or we dead
            throw std::runtime_error("Character are dead!!!");
        }
        else if(this == enemy){ // throw error when slash our self
            throw std::runtime_error("You can't slash yourself");
        }
        else{ // slash the enemy
            double dist = this->getLocation().distance(enemy->getLocation());
            if (isAlive() && dist < 1) {
                enemy->hit(40);
                isAttack = true;
            }
            else if(dist >= 1){
                isAttack = false;
            }
        }
    }

    string Ninja::print() const{
        // return "N " + this->getName() + " (" + to_string(this->getHealth()) + ") " + this->getLocation().toString() ;
        if (!isAlive()) {
            return "=N= {" + this->getName() + "}" + " died at " + this->getLocation().print() + "\n";
        } else {
            return "=N= " + this->getName() + " has (" + to_string(this->getHealth()) + " HP) at " + this->getLocation().print() + "\n";
        }
    }

    void Ninja::attack(Character* enemy){ // attack the enemy
        this->slash(enemy);
        if(!isAttack){ // when the distance bigger than or equal 1 -> move
            this->move(enemy);
        }
    }
    // =================================== End Ninja Functions ===================================

    
} 
