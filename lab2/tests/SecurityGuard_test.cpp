#include <UnitTest++/UnitTest++.h>
#include "people/SecurityGuard.h"
#include "spaces/Hall.h"
#include "spaces/Office.h"
#include "spaces/Cafe.h"
#include "exceptions/MuseumExceptions.h"

TEST(SecurityGuard_Patrol_CleanRoom) {
    Hall hall("Clean Hall", 10);
    hall.setClean(true); 

    SecurityGuard guard("Mike", "SG1");
    guard.assignRoom(hall);

    CHECK(guard.patrol()); 
}

TEST(SecurityGuard_Patrol_DirtyRoom) {
    Hall hall("Dirty Hall", 10);

    SecurityGuard guard("Mike", "SG1");
    guard.assignRoom(hall);

    CHECK(!guard.patrol()); 
}

TEST(SecurityGuard_EnforceCleanliness_Dirty_Throws) {
    Office office("Staff Office");

    SecurityGuard guard("Alice", "SG2");
    guard.assignRoom(office);

    CHECK_THROW(guard.enforceCleanliness(), HallIsDirtyException);
}

TEST(SecurityGuard_EnforceCleanliness_Clean_Ok) {
    Cafe cafe("Museum Cafe");
    cafe.setClean(true);

    SecurityGuard guard("Bob", "SG3");
    guard.assignRoom(cafe);

    guard.enforceCleanliness();
}