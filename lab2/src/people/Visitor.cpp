#include "Visitor.h"
#include "../events/Event.h"
#include "../exceptions/MuseumExceptions.h"

Visitor::Visitor(std::string name,
                 Ticket ticket,
                 double money,
                 short age,
                 char gender,
                 std::string membershipLevel)
    : Human(std::move(name), age, gender),
      money_(money),
      membershipLevel_(std::move(membershipLevel)), 
      ticket_(std::make_unique<Ticket>(std::move(ticket))) 
{
    if (membershipLevel_ != "Standard" &&
        membershipLevel_ != "Gold" &&
        membershipLevel_ != "VIP") 
        throw InvalidMembershipException();
        
    if (money_ < 0) 
        throw std::invalid_argument("Money cannot be negative");
}
void Visitor::enterHall(Hall& hall) const {
    if (!ticket() || ticket()->isExpired()) 
        throw TicketExpiredException();

    hall.addVisitor();
    currentHall_ = &hall;
}

void Visitor::leaveHall() const {
    if (currentHall_) {
        currentHall_->removeVisitor();
        currentHall_ = nullptr;
    }
}

void Visitor::attendEvent(Event& event) const {
    if (!event.location())
        throw std::runtime_error("Event has no location");
        
    enterHall(*event.location()); 
    event.addParticipant(const_cast<Visitor*>(this));
}

void Visitor::buyFromShop(Shop& shop, const std::string& itemName) {
    if (!shop.hasSouvenir(itemName)) 
        throw std::runtime_error("Item not in stock");

    double price = shop.getSouvenirPrice(itemName);
    spendMoney(price);
    shop.buySouvenir(itemName);
}

void Visitor::buyFromCafe(Cafe& cafe, const std::string& itemName) {
    if (!cafe.hasItem(itemName)) 
        throw std::runtime_error("Item not available");

    double price = cafe.getItemPrice(itemName);
    spendMoney(price);
    cafe.buyItem(itemName);
}

void Visitor::spendMoney(double amount) {
    if (amount < 0) 
        throw std::invalid_argument("Amount cannot be negative");
        
    if (amount > money_) 
        throw std::runtime_error("Insufficient funds");

    money_ -= amount;
}