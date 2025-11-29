#include "tech/Vehicle.h"

Vehicle::Vehicle(std::string licensePlate,
                             std::string vehicleType,
                             std::string purpose,
                             double maxPayloadKg,
                             bool hasClimateControl)
    : licensePlate_(std::move(licensePlate)),
      vehicleType_(std::move(vehicleType)),
      purpose_(std::move(purpose)),
      maxPayloadKg_(maxPayloadKg),
      hasClimateControl_(hasClimateControl) {}