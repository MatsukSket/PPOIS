#pragma once

#include "Human.h"
#include "finance/Ticket.h"
#include "spaces/Hall.h"
#include "spaces/Shop.h"
#include "spaces/Cafe.h"
#include "exceptions/MuseumExceptions.h"
#include <string>
#include <memory>

class Event;

class Visitor : public Human {
public:
    explicit Visitor(std::string name,
                     Ticket ticket,
                     double money = 0.0,
                     short age = 0,
                     char gender = 'U',
                     std::string membershipLevel = "Standard");

    const std::string& membershipLevel() const noexcept { return membershipLevel_; }
    const Ticket* ticket() const noexcept { return ticket_.get(); }
    Hall* currentHall() const noexcept { return currentHall_; } // текущий зал

    void enterHall(Hall& hall) const;
    void leaveHall() const;
    void attendEvent(Event& event) const;

    double money() const { return money_; }
    void spendMoney(double amount);
    void buyFromShop(Shop& shop, const std::string& itemName);
    void buyFromCafe(Cafe& cafe, const std::string& itemName);

private:
    double money_;
    std::string membershipLevel_;
    std::unique_ptr<Ticket> ticket_;
    mutable Hall* currentHall_ = nullptr;
};