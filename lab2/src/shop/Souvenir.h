#pragma once

#include <string>

class Souvenir {
public:
    Souvenir(std::string name, double price);
    virtual ~Souvenir() = default;

    virtual std::string getCategory() const = 0;
    const std::string& name() const { return name_; }
    double price() const { return price_; }

protected:
    std::string name_;
    double price_;
    std::string category_;
    double weightKg_;
    std::string material_;  
};