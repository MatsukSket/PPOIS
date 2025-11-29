#include "Ticket.h"

Ticket::Ticket(std::string ownerId, Type type, int durationHours)
    : ownerId_(std::move(ownerId)), type_(type),
      issueTime_(std::chrono::system_clock::now()),
      duration_(durationHours) {}

bool Ticket::isExpired() const noexcept {
    auto now = std::chrono::system_clock::now();
    return now > (issueTime_ + duration_);
}