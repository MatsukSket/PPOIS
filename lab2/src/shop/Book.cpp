#include "shop/Book.h"

Book::Book(std::string name, double price, std::string author)
    : Souvenir(std::move(name), price), author_(std::move(author)) {}