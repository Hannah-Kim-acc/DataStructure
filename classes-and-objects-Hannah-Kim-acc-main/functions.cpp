/*********************
Name: Che Hyun Kim
Coding 02
Purpose: This program displays a radius, area and perimeter of a circle and displays a radius, volume, area of a sphere.
**********************/

#include "functions.h"

void displayCircle(Circle *myCircle){
    std::cout<<myCircle->getRadius()<<std::endl;
    std::cout<<myCircle->getArea()<<std::endl;
    std::cout<<myCircle->getPerimeter()<<std::endl;
    std::cout<<std::endl;
}

void displaySphere(Sphere *mySphere) {
    std::cout<<mySphere->getRadius()<<std::endl;
    std::cout<<mySphere->getVolume()<<std::endl;
    std::cout<<mySphere->getArea()<<std::endl;
    std::cout<<std::endl;
}
