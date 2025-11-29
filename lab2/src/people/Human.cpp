#include "Human.h"

Human::Human(std::string name, short age, char gender)
    : name_(std::move(name)), age_(age), gender_(gender) {
        if (name_.empty()) 
            throw InvalidNameException();
        if (age_ < 0) 
            throw InvalidAgeException();
    }