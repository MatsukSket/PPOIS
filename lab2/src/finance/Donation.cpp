#include "finance/Donation.h"
#include <stdexcept>

Donation::Donation(Human* donor, double amount, std::string purpose)
    : donor_(donor), amount_(amount), purpose_(std::move(purpose)) {
    if (amount_ < 0) 
        throw std::invalid_argument("Amount cannot be negative");
}