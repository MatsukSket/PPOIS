#pragma once

#include <string>

class MenuItem {
public:
    MenuItem(std::string name, double price);
    virtual ~MenuItem() = default;

    virtual std::string getType() const = 0; 
    const std::string& name() const { return name_; }
    double price() const { return price_; }

protected:
    std::string name_;
    double price_;
    std::string category_;
    bool isVegetarian_;
    int calories_;
};