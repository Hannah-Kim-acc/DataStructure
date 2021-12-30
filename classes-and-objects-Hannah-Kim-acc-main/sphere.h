/*********************
Name: Che Hyun Kim
Coding 02
Purpose: This program displays a radius, area and perimeter of a circle and displays a radius, volume, area of a sphere.
**********************/

#ifndef CLASSES_SPHERE_H
#define CLASSES_SPHERE_H

#include "circle.h"

class Sphere : public Circle{
public:
    Sphere();
    Sphere(int);
    ~Sphere();
    
    float getVolume();
    float getArea();
};

#endif
