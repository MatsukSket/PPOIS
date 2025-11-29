#include "spaces/StorageRoom.h"
#include <UnitTest++/UnitTest++.h>

TEST(StorageRoom_ValidConstruction) {
    StorageRoom room("Art Storage", 18.5);
    CHECK_EQUAL("Art Storage", room.name());
    CHECK_CLOSE(18.5, room.climateControlTempC(), 0.001);
    CHECK_EQUAL("Main Building", room.location());
}

TEST(StorageRoom_AdjustTemperature_Valid) {
    StorageRoom room("Climate Room", 20.0);
    room.adjustTemperature(22.5);
    CHECK_CLOSE(22.5, room.climateControlTempC(), 0.001);
}

TEST(StorageRoom_DefaultTemperature) {
    StorageRoom room("Default");
    CHECK_CLOSE(20.0, room.climateControlTempC(), 0.001);
}