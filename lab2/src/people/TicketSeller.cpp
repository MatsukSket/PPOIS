#include "TicketSeller.h"
#include "../exceptions/MuseumExceptions.h"

TicketSeller::TicketSeller(std::string name,
                           std::string employeeId,
                           short age,
                           char gender)
    : Employee(std::move(name), std::move(employeeId), "Ticket Seller", age, gender) {}

Ticket TicketSeller::sellTicket(const std::string& visitorName, Ticket::Type type) const {
    if (visitorName.empty()) {
        throw InvalidNameException();
    }
    return Ticket(visitorName, type);
}