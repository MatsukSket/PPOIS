#pragma once

#include "Employee.h"
#include "finance/Ticket.h"
#include <string>

class TicketSeller : public Employee {
public:
    explicit TicketSeller(std::string name,
                          std::string employeeId,
                          short age = 0,
                          char gender = 'U');

    Ticket sellTicket(const std::string& visitorName, Ticket::Type type = Ticket::Type::STANDARD) const;
};
