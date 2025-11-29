#include "GiftCard.h"
#include <stdexcept>

GiftCard::GiftCard(std::string cardNumber,
                   double balance,
                   std::string ownerName,
                   std::string expiryDate)
    : cardNumber_(std::move(cardNumber)),
      balance_(balance),
      ownerName_(std::move(ownerName)),
      expiryDate_(std::move(expiryDate)) {
    if (cardNumber_.empty()) {
        throw std::invalid_argument("Card number must not be empty");
    }
    if (balance_ < 0.0) {
        throw std::invalid_argument("Balance cannot be negative");
    }
    if (ownerName_.empty()) {
        throw std::invalid_argument("Owner name must not be empty");
    }
    if (expiryDate_.empty()) {
        throw std::invalid_argument("Expiry date must not be empty");
    }
}