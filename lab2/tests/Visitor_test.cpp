#include "people/Visitor.h"
#include "finance/Ticket.h"
#include "exceptions/MuseumExceptions.h"
#include "spaces/Hall.h"
#include "exhibits/Exhibit.h"
#include "events/Lecture.h"
#include "spaces/Cafe.h"
#include "spaces/Shop.h"
#include "shop/Souvenir.h"
#include "shop/MenuItem.h"
#include <UnitTest++/UnitTest++.h>

TEST(Visitor_ValidConstruction) {
    Ticket t("V1", Ticket::Type::STANDARD);
    Visitor v("Elena", t, 100.0, 28, 'F', "Gold");
    CHECK_EQUAL("Elena", v.name());
    CHECK_EQUAL("Gold", v.membershipLevel());
    CHECK_CLOSE(100.0, v.money(), 0.001);
    CHECK(v.ticket() != nullptr);
}

TEST(Visitor_InvalidMembership_Throws) {
    Ticket t("X", Ticket::Type::STUDENT);
    CHECK_THROW(
        Visitor("Bad", t, 0, 0, 'U', "Platinum"),
        InvalidMembershipException
    );
}

TEST(Visitor_NegativeMoney_Throws) {
    Ticket t("X", Ticket::Type::VIP);
    CHECK_THROW(
        Visitor("Poor", t, -10.0, 20, 'M', "Standard"),
        std::invalid_argument
    );
}

TEST(Visitor_SpendMoney_Valid) {
    Ticket t("V", Ticket::Type::STANDARD);
    Visitor v("Tom", t, 50.0);
    v.spendMoney(20.0);
    CHECK_CLOSE(30.0, v.money(), 0.001);
}

TEST(Visitor_SpendMoney_InsufficientFunds_Throws) {
    Ticket t("V", Ticket::Type::STUDENT);
    Visitor v("Rich", t, 10.0);
    CHECK_THROW(v.spendMoney(15.0), std::runtime_error);
}

TEST(Visitor_SpendMoney_NegativeAmount_Throws) {
    Ticket t("V", Ticket::Type::VIP);
    Visitor v("Normal", t, 20.0);
    CHECK_THROW(v.spendMoney(-5.0), std::invalid_argument);
}