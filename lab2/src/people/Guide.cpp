#include "Guide.h"
#include "../exceptions/MuseumExceptions.h"
#include <stdexcept>

Guide::Guide(std::string name, std::string employeeId, short age, char gender)
    : Employee(std::move(name), std::move(employeeId), "Museum Guide", age, gender) {}

std::string Guide::conductTour(const std::vector<Visitor*>& visitors, const Exhibit& exhibit) const {
    if (!exhibit.isOpen()) 
        throw std::runtime_error("Cannot conduct tour: exhibit is closed");
        
    if (visitors.empty()) 
        throw std::runtime_error("No visitors in the group");
        
    for (const auto* v : visitors) {
        if (!v || !v->ticket() || v->ticket()->isExpired()) 
            throw TicketExpiredException();
    }
    return "Guide " + name() + " conducted a tour for " +
           std::to_string(visitors.size()) + " visitors at exhibit '" +
           exhibit.name() + "'";
}