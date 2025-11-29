#include "people/Guide.h"
#include "exhibits/Exhibit.h"
#include "finance/Ticket.h"
#include "exceptions/MuseumExceptions.h"
#include <UnitTest++/UnitTest++.h>

TEST(Guide_ConductTour_ExhibitClosed_Throws) {
    Exhibit ex("Closed", 2);
    ex.setOpen(false);
    Guide guide("Emma", "G001");
    Ticket t("V", Ticket::Type::STANDARD);
    Visitor v("Alice", t);
    std::vector<Visitor*> visitors = {&v};

    CHECK_THROW(guide.conductTour(visitors, ex), std::runtime_error);
}

TEST(Guide_ConductTour_ExpiredTicket_Throws) {
    Exhibit ex("Open", 3);
    ex.setOpen(true);
    Guide guide("Liam", "G002");
    // Создаём Visitor с просроченным билетом (duration=0)
    Ticket expired("V", Ticket::Type::VIP, 0);
    Visitor v("Bob", expired);
    std::vector<Visitor*> visitors = {&v};

    CHECK_THROW(guide.conductTour(visitors, ex), TicketExpiredException);
}