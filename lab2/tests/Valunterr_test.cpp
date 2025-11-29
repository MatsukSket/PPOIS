#include "people/Valunteer.h"
#include <UnitTest++/UnitTest++.h>

TEST(Volunteer_ValidConstruction) {
    Volunteer v("Noah", 22, 'M', "Education", 10, "Dr. Smith", true);
    CHECK_EQUAL("Noah", v.name());
    CHECK_EQUAL("Education", v.department());
    CHECK_EQUAL(10, v.hoursPerWeek());
    CHECK_EQUAL("Dr. Smith", v.supervisor());
    CHECK_EQUAL(true, v.hasTraining());
}

TEST(Volunteer_DefaultValues) {
    Volunteer v("Default", 25, 'U');
    CHECK_EQUAL("General", v.department());
    CHECK_EQUAL(0, v.hoursPerWeek());
    CHECK_EQUAL("Admin", v.supervisor());
    CHECK_EQUAL(false, v.hasTraining());
}