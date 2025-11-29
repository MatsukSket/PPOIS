#include "exhibits/Sculpture.h"
#include <UnitTest++/UnitTest++.h>

TEST(Sculpture_Ctor_InitializesFields) {
    Sculpture s("Thinker", "Rodin", "Bronze", 750.5);
    CHECK_EQUAL("Thinker", s.title());
    CHECK_EQUAL("Rodin", s.artist());
    CHECK_EQUAL("Bronze", s.material());
    CHECK_CLOSE(750.5, s.weightKg(), 0.001);
}

TEST(Sculpture_GetInfo_FormatsCorrectly) {
    Sculpture s("Venus", "Unknown", "Marble", 200.0);
    std::string info = s.getInfo();
    CHECK(info.find("Sculpture: \"Venus\"") != std::string::npos);
    CHECK(info.find("Marble") != std::string::npos);
    CHECK(info.find("200 kg") != std::string::npos);
}
