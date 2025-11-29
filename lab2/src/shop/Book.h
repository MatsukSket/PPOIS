#pragma once

#include "Souvenir.h"
#include <string>

class Book : public Souvenir {
public:
    Book(std::string name, double price, std::string author = "Unknown");

    const std::string& author() const { return author_; }
    std::string getCategory() const override { return "Book"; }

private:
    std::string author_;
    std::string isbn_;
    int pagesCount_;
};