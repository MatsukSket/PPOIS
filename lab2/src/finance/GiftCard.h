#pragma once
#include <string>
#include <stdexcept>

class GiftCard {
public:
    GiftCard(std::string cardNumber = "GC000",
             double balance = 0.0,
             std::string ownerName = "Unknown",
             std::string expiryDate = "2030-12-31");

    const std::string& cardNumber() const noexcept { return cardNumber_; }
    double balance() const noexcept { return balance_; }
    const std::string& ownerName() const noexcept { return ownerName_; }
    const std::string& expiryDate() const noexcept { return expiryDate_; }

private:
    std::string cardNumber_;
    double balance_;
    std::string ownerName_;
    std::string expiryDate_;
};