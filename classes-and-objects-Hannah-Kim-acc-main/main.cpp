/*********************
Name: Che Hyun Kim
Coding 02
Purpose: This program displays a radius, area and perimeter of a circle and displays a radius, volume, area of a sphere.
**********************/
#include "main.h"
int main(int argc, char** argv) {
    
    Circle myCircle1;
    Circle myCircle2(5);
    
    Sphere mySphere1;
    Sphere mySphere2(5);
    
    displayCircle(&myCircle1);
    displayCircle(&myCircle2);
    
    displaySphere(&mySphere1);
    displaySphere(&mySphere2);
    
    
    return 0;
    
}
