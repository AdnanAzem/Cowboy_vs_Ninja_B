#include "Point.hpp"
#include <cmath>
namespace ariel{
    Point::Point(): coordinate_x(0), coordinate_y(0){

    }

    Point::Point(double x, double y): coordinate_x(x), coordinate_y(y){

    }

    double Point::distance(const Point& other) const{
        double dx = coordinate_x - other.coordinate_x;
        double dy = coordinate_y - other.coordinate_y;
        return std::sqrt(dx * dx + dy * dy);
    }



    void Point::print(){
        std::cout << "(" << coordinate_x << ", " << coordinate_y << ")" << std::endl;
    }

    // Point Point::moveToward(const Point& source, const Point& target, double distance){
        
    //     double dist = this->distance(target);
    //     if (dist <= distance) {
    //         return target;
    //     } else {
    //         double dx = target.coordinate_x - coordinate_x;
    //         double dy = target.coordinate_y - coordinate_y;
    //         double scale = distance / dist;
    //         dx *= scale;
    //         dy *= scale;
    //         return Point(coordinate_x + dx, coordinate_y + dy);
    //     }
    // }

    Point Point::moveTowards(const Point& source, const Point& target, double distance){
        if(distance < 0){
            throw std::invalid_argument("distance must be positive");
        }
        double dist = source.distance(target);
        if (dist <= distance) {
            return target;
        } else {
            double dx = target.get_x() - source.get_x();
            double dy = target.get_y() - source.get_y();
            double scale = distance / dist;
            dx *= scale;
            dy *= scale;
            return Point(source.get_x() + dx, source.get_y() + dy);
        }
    }


    string Point::toString() const{
        return "(" + to_string(coordinate_x) + ", " + to_string(coordinate_y) + ")" ;
    }
    
}