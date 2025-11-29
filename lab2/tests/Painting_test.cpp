#include "exhibits/Painting.h"
#include <UnitTest++/UnitTest++.h>

TEST(Painting_Ctor_InitializesFields) {
    Painting p("Mona Lisa", "Da Vinci", "Renaissance", 1503);
    CHECK_EQUAL("Mona Lisa", p.title());
    CHECK_EQUAL("Da Vinci", p.artist());
    CHECK_EQUAL("Renaissance", p.getStyle());
    CHECK_EQUAL(1503, p.getYear());
}

TEST(Painting_GetInfo_FormatsCorrectly) {
    Painting p("Water Lilies", "Monet", "Impressionism", 1916);
    std::string info = p.getInfo();
    CHECK(info.find("Painting: \"Water Lilies\"") != std::string::npos);
    CHECK(info.find("Monet") != std::string::npos);
    CHECK(info.find("1916") != std::string::npos);
    CHECK(info.find("Impressionism") != std::string::npos);
}
