#pragma once

#include <string>

class Human;

class Donation {
public:
    Donation(Human* donor, double amount, std::string purpose = "General");
    ~Donation() = default;

    Human* donor() const { return donor_; }
    double amount() const { return amount_; }
    const std::string& purpose() const { return purpose_; }

private:
    Human* donor_;
    double amount_;
    std::string purpose_;
};