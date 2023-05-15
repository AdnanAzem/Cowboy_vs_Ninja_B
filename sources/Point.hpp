#pragma once
#include <iostream>
using namespace std;
namespace ariel{

    class Point{
        private:
            double coordinate_x;
            double coordinate_y;

        public:
            Point();
            Point(double, double);

            // Getters
            double get_x() const{return this->coordinate_x;}
            double get_y() const{return this->coordinate_y;}

            double distance(const Point&) const; // return the distance between 2 points
            void print(); // print the point example: (2,2)
            string toString() const;
            // Point moveToward(const Point&, const Point&, double); // return the closest point 
            static Point moveTowards(const Point&, const Point&, double); // return the closest point 

    };
}