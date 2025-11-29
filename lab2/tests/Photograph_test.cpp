#include "exhibits/Photograph.h"
#include <UnitTest++/UnitTest++.h>

TEST(Photograph_Ctor_InitializesFields) {
    Photograph p("Earthrise", "Bill Anders", 1968, true);
    CHECK_EQUAL("Earthrise", p.title());
    CHECK_EQUAL("Bill Anders", p.artist());
    CHECK_EQUAL(1968, p.year());
    CHECK_EQUAL(true, p.isColor());
}

TEST(Photograph_GetInfo_Color) {
    Photograph p("Sunset", "John", 2020, true);
    std::string info = p.getInfo();
    CHECK(info.find("Color") != std::string::npos);
}

TEST(Photograph_GetInfo_BlackAndWhite) {
    Photograph p("Factory", "Lewis Hine", 1910, false);
    std::string info = p.getInfo();
    CHECK(info.find("Black & White") != std::string::npos);
}
