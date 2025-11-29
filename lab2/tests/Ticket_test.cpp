#include <UnitTest++/UnitTest++.h>
#include "finance/Ticket.h"

TEST(Ticket_Valid) {
    Ticket t("V1", Ticket::Type::VIP, 10);
    CHECK(!t.isExpired());
}

TEST(Ticket_ImmediateExpiry) {
    Ticket t("V1", Ticket::Type::STANDARD, 0);
    CHECK(t.isExpired());
}