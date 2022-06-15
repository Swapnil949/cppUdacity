#include <assert.h>
#include <cmath>
#include <iostream>

// Define pi
#define PI 3.14159

struct LineSegment {
public:
    double length;
};

// Define Line Class

// Define protected attribute length

// Define Circle subclass
class Circle {
private:
    LineSegment& radius_;

public:
    Circle(LineSegment& radius)
        : radius_(radius) {};

    double Area()
    {
        return pow(radius_.length, 2) * PI;
    }
};

// Define public setRadius() and getArea()

// Test in main()
int
main()
{
    LineSegment radius { 3 };
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}