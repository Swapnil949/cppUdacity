// Example solution for Rectangle and Square friend classes
#include <assert.h>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square {
private:
    // Add friend class Rectangle
    friend class Rectangle;

    // Add private attribute side
    int side;

public:
    // Add public constructor to Square, initialize side
    Square(int s) : side(s) {}
};

// Define class Rectangle
class Rectangle {
private:
    // Add private attributes width, height;
    int width = { 0 };
    int height = { 0 };

public:
    // Add public function to Rectangle: Area()
    int Area() const;
    // Define a Rectangle constructor that takes a Square
    Rectangle(const Square& a);
};

Rectangle::Rectangle(const Square& a)
    : width(a.side)
    , height(a.side)
{
}

// Define Area() to compute area of Rectangle
int Rectangle::Area() const 
{
    return width*height;
}

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}