/*********************
Name: Che Hyun Kim
Coding 02
Purpose: This program displays a radius, area and perimeter of a circle and displays a radius, volume, area of a sphere. 
**********************/
#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

#define MIN 0
#define PI 3.14

class Circle {
    
public:
    
    Circle();
    Circle(int);
    ~Circle();
    
    int getRadius();
    float getArea();
    float getPerimeter();
    
    void setRadius(int);

protected:
    int radius;
};


#endif
