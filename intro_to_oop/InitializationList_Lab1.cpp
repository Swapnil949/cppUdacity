#include <assert.h>
#include <string>

// TODO: Define class Person
// TODO: Define a public constructor with an initialization list
// TODO: Define a public member variable: name

class Person
{
public:
  Person(std::string name)
    : name(name)
  {}

  std::string const name;
};

// Test
int
main()
{
  Person alice("Alice");
  Person bob("Bob");
  assert(alice.name != bob.name);
}