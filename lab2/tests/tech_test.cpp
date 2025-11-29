#include "tech/Alarm.h"
#include "tech/Camera.h"
#include "tech/ClimateControl.h"
#include "tech/LightningSystem.h"
#include "tech/Vehicle.h"
#include "spaces/Office.h"
#include <UnitTest++/UnitTest++.h>



TEST(Alarm_ValidConstruction) {
    Office office("Security Room");
    Alarm alarm(&office);
    CHECK_EQUAL(&office, alarm.getLocation());
    CHECK(!alarm.isActive());
}

TEST(Alarm_Activate_Deactivate) {
    Office office("Room");
    Alarm alarm(&office);
    alarm.activate();
    CHECK(alarm.isActive());
    alarm.deactivate();
    CHECK(!alarm.isActive());
}



TEST(Camera_ValidConstruction) {
    Office office("Hall Entrance");
    Camera cam(&office, true);
    CHECK_EQUAL(&office, cam.getLocation());
    CHECK(cam.isRecording());
}

TEST(Camera_DefaultNotRecording) {
    Office office("Storage");
    Camera cam(&office);
    CHECK(!cam.isRecording());
}



TEST(ClimateControl_ValidConstruction) {
    ClimateControl cc(22.5, 45.0);
    CHECK_CLOSE(22.5, cc.targetTempC(), 0.001);
    CHECK_CLOSE(45.0, cc.humidityPercent(), 0.001);
}



TEST(LightningSystem_ValidConstruction) {
    LightningSystem ls("Halogen", 800.0, 3000.0, true);
    CHECK_EQUAL("Halogen", ls.type());
    CHECK_CLOSE(800.0, ls.intensityLux(), 0.001);
    CHECK_CLOSE(3000.0, ls.colorTemperatureK(), 0.001);
    CHECK_EQUAL(true, ls.isMotionActivated());
}

TEST(LightningSystem_DefaultValues) {
    LightningSystem ls;
    CHECK_EQUAL("LED", ls.type());
    CHECK_CLOSE(500.0, ls.intensityLux(), 0.001);
    CHECK_CLOSE(4000.0, ls.colorTemperatureK(), 0.001);
    CHECK_EQUAL(false, ls.isMotionActivated());
}

TEST(Vehicle_ValidConstruction) {
    Vehicle v("MUS-2025", "Truck", "Artifact Transport", 2500.0, true);
    CHECK_EQUAL("MUS-2025", v.licensePlate());
    CHECK_EQUAL("Truck", v.vehicleType());
    CHECK_EQUAL("Artifact Transport", v.purpose());
    CHECK_CLOSE(2500.0, v.maxPayloadKg(), 0.001);
    CHECK_EQUAL(true, v.hasClimateControl());
}

TEST(MuseumVehicle_DefaultValues) {
    Vehicle v("TEST-001");
    CHECK_EQUAL("Van", v.vehicleType());
    CHECK_EQUAL("Transport", v.purpose());
    CHECK_CLOSE(1000.0, v.maxPayloadKg(), 0.001);
    CHECK_EQUAL(false, v.hasClimateControl());
}