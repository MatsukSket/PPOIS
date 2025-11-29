#include "people/TicketSeller.h"
#include "exceptions/MuseumExceptions.h"
#include <UnitTest++/UnitTest++.h>

TEST(TicketSeller_SellTicket_Valid) {
    TicketSeller seller("Alice", "TS001");
    Ticket t = seller.sellTicket("Bob", Ticket::Type::STUDENT);
    CHECK_EQUAL("Bob", t.ownerId());
    CHECK(t.type() == Ticket::Type::STUDENT);
}

TEST(TicketSeller_SellTicket_EmptyName_Throws) {
    TicketSeller seller("Seller", "TS002");
    CHECK_THROW(seller.sellTicket(""), InvalidNameException);
}