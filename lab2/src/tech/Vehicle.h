#pragma once
#include <string>

class Vehicle {
public:
    Vehicle(std::string licensePlate,
                  std::string vehicleType = "Van",
                  std::string purpose = "Transport",
                  double maxPayloadKg = 1000.0,
                  bool hasClimateControl = false);

    const std::string& licensePlate() const { return licensePlate_; }
    const std::string& vehicleType() const { return vehicleType_; }
    const std::string& purpose() const { return purpose_; }
    double maxPayloadKg() const { return maxPayloadKg_; }
    bool hasClimateControl() const { return hasClimateControl_; }

private:
    std::string licensePlate_;
    std::string vehicleType_;
    std::string purpose_;
    double maxPayloadKg_;
    bool hasClimateControl_;
};