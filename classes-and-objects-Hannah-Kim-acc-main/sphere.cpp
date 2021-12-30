/*********************
Name: Che Hyun Kim
Coding 02
Purpose: This program displays a radius, area and perimeter of a circle and displays a radius, volume, area of a sphere.
**********************/

#include "sphere.h"

Sphere::Sphere() {
    setRadius(MIN);
}

Sphere::Sphere(int r) {
    setRadius(r);
}

Sphere::~Sphere() {
}

float Sphere::getVolume() {
    return ((float)4/(float)3) * PI * ( radius * radius * radius );
}
float Sphere::getArea() {
    return 4 * PI * (radius * radius);
}


