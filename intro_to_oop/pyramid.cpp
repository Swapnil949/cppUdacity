#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid

class Pyramid {
private:
    /* data */
    int length;
    int width;
    int height;
    void checkInput();

public:
    Pyramid(int length, int width, int height);

    // accessors (getters)
    int getLength() const { return this->length; }
    int getWidth() const { return this->width; }
    int getHeight() const { return this->height; }

    // Mutators (setters)
    void setLength(int length) { this->length = length; }
    void setWidth(int width) { this->width = width; }
    void setHeight(int height) { this->height = height; }

    // Calculate volume
    int calculateVolume();
};

// public class members

// constructor
Pyramid::Pyramid(int length, int width, int height)
{
    if (length <= 0 || width <= 0 || height <= 0)
        throw std::invalid_argument("Invalid dimension");

    this->length = length;
    this->width = width;
    this->height = height;
}

// public Volume() function
//
int Pyramid::calculateVolume()
{
    return this->length * this->width * this->height / 3;
}

// Test
int main()
{
    Pyramid pyramid(4, 5, 6);
#if 1
    assert(pyramid.getLength() == 4);
    assert(pyramid.getWidth() == 5);
    assert(pyramid.getHeight() == 6);
    assert(pyramid.calculateVolume() == 40);

    bool caught { false };
    try {
        Pyramid invalid(-1, 2, 3);
    } catch (...) {
        caught = true;
    }
    assert(caught);
#endif
}