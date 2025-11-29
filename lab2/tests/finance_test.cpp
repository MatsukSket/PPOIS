#include "finance/Ticket.h"
#include "finance/Donation.h"
#include "finance/GiftCard.h"
#include "finance/MuseumPass.h"
#include "people/Human.h"
#include <UnitTest++/UnitTest++.h>
#include <thread>
#include <chrono>

TEST(Ticket_Ctor_SetsFieldsCorrectly) {
    Ticket t("V123", Ticket::Type::VIP, 12);
    CHECK_EQUAL("V123", t.ownerId());
    CHECK(t.type() == Ticket::Type::VIP);
    CHECK(!t.isExpired()); 
}

TEST(Ticket_IsExpired_NeverExpiresWithinDuration) {
    Ticket t("User", Ticket::Type::STUDENT, 1);
    CHECK(!t.isExpired());
}

TEST(Ticket_IsExpired_ExpiresAfterDuration) {
    Ticket t("Fast", Ticket::Type::STANDARD, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    CHECK(t.isExpired());
}

TEST(Donation_Ctor_SetsFieldsCorrectly) {
    class TestHuman : public Human {
    public:
        TestHuman() : Human("Donor", 40, 'F') {}
    } donor;

    Donation d(&donor, 150.75, "Restoration");
    CHECK_EQUAL(&donor, d.donor());
    CHECK_CLOSE(150.75, d.amount(), 0.001);
    CHECK_EQUAL("Restoration", d.purpose());
}

TEST(Donation_Ctor_DefaultPurpose) {
    class TestHuman : public Human {
    public:
        TestHuman() : Human("Anonymous", 30, 'U') {}
    } donor;

    Donation d(&donor, 50.0);
    CHECK_EQUAL("General", d.purpose());
}

TEST(GiftCard_DefaultInitialization) {
    GiftCard card;
}

TEST(MuseumPass_DefaultInitialization) {
    MuseumPass pass;
    CHECK(true);
}