#include "tech/LightningSystem.h"

LightningSystem::LightningSystem(std::string type,
                                 double intensityLux,
                                 double colorTemperatureK,
                                 bool isMotionActivated)
    : type_(std::move(type)),
      intensityLux_(intensityLux),
      colorTemperatureK_(colorTemperatureK),
      isMotionActivated_(isMotionActivated) {}