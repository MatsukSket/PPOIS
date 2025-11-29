#include "people/Human.h"
#include "exceptions/MuseumExceptions.h"
#include <UnitTest++/UnitTest++.h>

TEST(Human_ValidConstruction) {
    Human h("Alice", 25, 'F');
    CHECK_EQUAL("Alice", h.name());
    CHECK_EQUAL(25, h.age());
    CHECK_EQUAL('F', h.gender());
}

TEST(Human_EmptyName_Throws) {
    CHECK_THROW(Human("", 30, 'M'), InvalidNameException);
}

TEST(Human_NegativeAge_Throws) {
    CHECK_THROW(Human("Bob", -5, 'M'), InvalidAgeException);
}