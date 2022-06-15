/*
Instructions
    Define a class Animal.
    Define 3 member variables: color, name, age.

    Define a derived class Snake that inherits from the base class Animal.
    Create a member variable length for the Snake class.
    Create a derived class Cat that inherits from the base class Animal.
    Create a member variable height for the Cat class.

    Create MakeSound() member functions for each of the derived classes.
    In the main() function instantiate Snake and Cat objects. Initialize both their unique and derived attributes. Program them to make a sound.
 */

#include <iostream>
#include <string>

class Animal {
private:

public:
    /* data */
    std::string color;
    std::string name;
    int age;

    Animal(/* args */);
    ~Animal();
};

// constructor
Animal::Animal(/* args */)
{
}

// destructor
Animal::~Animal()
{
}

class Snake : public Animal {
public:
    int length;
    void MakeSound() const
    {
        std::cout << "Hiss\n";
    }
};

class Cat : public Animal {
public:
    int height;
    void MakeSound() const
    {
        std::cout << "Meow\n";
    }
};

int main()
{
    Cat cat;
    Snake snake;

    cat.age = 10;
    cat.name = "Lucy";
    cat.MakeSound();
    snake.MakeSound();

    std::cout << cat.age << " " << cat.name << "\n";
}