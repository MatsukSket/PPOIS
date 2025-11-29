#include "finance/MuseumPass.h"
#include <stdexcept>

MuseumPass::MuseumPass(std::string passId,
                       std::string ownerName,
                       std::string passType,
                       std::string validFrom,
                       std::string validUntil,
                       int entryCount)
    : passId_(std::move(passId)),
      ownerName_(std::move(ownerName)),
      passType_(std::move(passType)),
      validFrom_(std::move(validFrom)),
      validUntil_(std::move(validUntil)),
      entryCount_(entryCount) {
    if (passId_.empty()) {
        throw std::invalid_argument("Pass ID must not be empty");
    }
    if (ownerName_.empty()) {
        throw std::invalid_argument("Owner name must not be empty");
    }
    if (passType_.empty()) {
        throw std::invalid_argument("Pass type must not be empty");
    }
    if (validFrom_.empty() || validUntil_.empty()) {
        throw std::invalid_argument("Valid dates must not be empty");
    }
    if (entryCount_ < 0) {
        throw std::invalid_argument("Entry count cannot be negative");
    }
}