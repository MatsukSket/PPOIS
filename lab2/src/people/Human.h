#pragma once
#include <string>
#include "../exceptions/MuseumExceptions.h"

class Human {
public:
    explicit Human(std::string name, short age = 0, char gender = 'U');
    virtual ~Human() = default;

    const std::string& name() const noexcept { return name_; }
    short age() const noexcept { return age_; }
    char gender() const noexcept { return gender_; }


private:
    std::string name_;
    short age_;
    char gender_;
    std::string email_;
    std::string phoneNumber_;
    int visitCount_;
    bool isMember_;
    int height_;
};