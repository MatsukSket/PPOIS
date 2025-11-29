#include "exhibits/Exhibit.h"
#include "exhibits/Painting.h"
#include "exhibits/Sculpture.h"
#include "exceptions/MuseumExceptions.h"
#include <UnitTest++/UnitTest++.h>

TEST(Exhibit_Ctor_SetsNameAndCapacity) {
    Exhibit ex("Modern Art", 10);
    CHECK_EQUAL("Modern Art", ex.name());
    CHECK_EQUAL(10, ex.capacity());
    CHECK_EQUAL(0, ex.size());
    CHECK(!ex.isOpen());
}

TEST(Exhibit_AddArtwork_Valid) {
    Exhibit ex("Renaissance", 3);
    Painting* p = new Painting("Last Supper", "Da Vinci");
    ex.addArtwork(p);
    CHECK_EQUAL(1, ex.size());
}

TEST(Exhibit_AddArtwork_NullPtr_Throws) {
    Exhibit ex("Empty", 1);
    CHECK_THROW(ex.addArtwork(nullptr), std::invalid_argument);
}

TEST(Exhibit_AddArtwork_ExceedsCapacity_Throws) {
    Exhibit ex("Tiny", 1);
    Painting* p1 = new Painting("A", "X");
    Painting* p2 = new Painting("B", "Y");
    ex.addArtwork(p1);
    CHECK_EQUAL(1, ex.size());
    CHECK_THROW(ex.addArtwork(p2), std::runtime_error);
}

TEST(Exhibit_GetArtworkInfo_ReturnsAllInfos) {
    Exhibit ex("Mixed", 2);
    Painting* p = new Painting("Sky", "Artist");
    Sculpture* s = new Sculpture("Statue", "Sculptor", "Stone", 100.0);
    ex.addArtwork(p);
    ex.addArtwork(s);

    std::vector<std::string> infos = ex.getArtworkInfo();
    CHECK_EQUAL(2, infos.size());
    CHECK(infos[0].find("Painting") != std::string::npos);
    CHECK(infos[1].find("Sculpture") != std::string::npos);
}

TEST(Exhibit_SetOpen_TogglesState) {
    Exhibit ex("ClosedExhibit", 1);
    CHECK(!ex.isOpen());
    ex.setOpen(true);
    CHECK(ex.isOpen());
    ex.setOpen(false);
    CHECK(!ex.isOpen());
}
