/*********************
Name: Che Hyun Kim
Coding 02
Purpose: This program displays a radius, area and perimeter of a circle and displays a radius, volume, area of a sphere.
**********************/

#include "circle.h"

Circle::Circle() {
    setRadius(MIN);
}

Circle::Circle(int r) {
    setRadius(r);
}

Circle::~Circle() {
}

int Circle::getRadius() {
    return radius;
}

float Circle::getPerimeter(){
    return 2 * radius * PI;
}

float Circle::getArea() {
    return radius * radius * PI;
}

void Circle::setRadius(int r) {
    if(r>0) {
        radius = r;
    }
    else {
        radius = MIN;
    }
}

