#include "spaces/Office.h"
#include <UnitTest++/UnitTest++.h>

TEST(Office_GetDescription_Dirty) {
    Office office("Storage");
    std::string desc = office.getDescription();
    CHECK(desc.find("dirty") != std::string::npos);
}

TEST(Office_GetDescription_Clean) {
    Office office("Director");
    office.setClean(true);
    std::string desc = office.getDescription();
    CHECK(desc.find("clean") != std::string::npos);
}

TEST(Office_NameAndLocation_Correct) {
    Office office("HR Office");
    CHECK_EQUAL("HR Office", office.name());
    CHECK_EQUAL("Staff Area", office.location());
}