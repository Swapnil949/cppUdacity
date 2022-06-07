#include <cassert>
#include <stdexcept>
#include <string>

using std::string;

// TODO: Define "Student" class
class Student {

private:
    string name_;
    uint8_t grade_;
    double gpa_;
    void validate()
    {
        bool isValid = true;

        if (getGrade() < 0 || getGrade() > 12)
            isValid = false;

        if (getGpa() < 0.0 || getGpa() > 4.0)
            isValid = false;

        if (!isValid)
            throw std::invalid_argument("Invalid Parameter");
    }

public:
    // constructor
    Student(string name, uint8_t grade, double gpa)
        : name_(name)
        , grade_(grade)
        , gpa_(gpa)
    {
        validate();
    }
    // accessors
    string getName() const { return this->name_; }
    uint8_t getGrade() const { return this->grade_; }
    double getGpa() const { return this->gpa_; }

    // mutators
    void setName(string name)
    {
        this->name_ = name;
        validate();
    }

    void setGrade(uint8_t grade)
    {
        this->grade_ = grade;
        validate();
    }

    void setGpa(double gpa)
    {
        this->gpa_ = gpa;
        validate();
    }
};

// TODO: Test
int main() {
    Student david("David Silver", 10, 4.0);
    assert(david.getName() == "David Silver");
    assert(david.getGrade() == 10);
    assert(david.getGpa() == 4.0);
    
    bool caught{false};
    try {
        david.setGrade(20);
    }
    catch(...) {
        caught = true;
    }
    assert(caught);
}