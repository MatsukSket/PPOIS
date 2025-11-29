#pragma once
#include <string>
#include <chrono>

class Ticket {
public:
    enum class Type { STANDARD, VIP, STUDENT };

    Ticket(std::string ownerId, Type type = Type::STANDARD, int durationHours = 8);

    const std::string& ownerId() const noexcept { return ownerId_; }
    Type type() const noexcept { return type_; }
    bool isExpired() const noexcept;

private:
    std::string ownerId_;
    Type type_;
    std::chrono::system_clock::time_point issueTime_;
    std::chrono::hours duration_;
};