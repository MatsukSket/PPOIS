#include "exhibits/Sculpture.h"
#include "exhibits/Painting.h"
#include "exhibits/Photograph.h"
#include <UnitTest++/UnitTest++.h>

TEST(Artwork_Getters_ReturnCorrectValues) {
    Painting p("Starry Night", "Van Gogh", "Post-Impressionism", 1889);
    CHECK_EQUAL("Starry Night", p.title());
    CHECK_EQUAL("Van Gogh", p.artist());
}

TEST(Artwork_GetInfo_VirtualDispatch) {
    Sculpture s("David", "Michelangelo", "Marble", 5000.0);
    Photograph ph("Moon", "NASA", 1969, true);

    std::string sInfo = s.getInfo();
    std::string phInfo = ph.getInfo();

    CHECK(sInfo.find("Sculpture") != std::string::npos);
    CHECK(phInfo.find("Photograph") != std::string::npos);
    CHECK(phInfo.find("Color") != std::string::npos);
}
