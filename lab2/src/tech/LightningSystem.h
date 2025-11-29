#pragma once
#include <string>

class LightningSystem {
public:
    LightningSystem(std::string type = "LED",
                    double intensityLux = 500.0,
                    double colorTemperatureK = 4000.0,
                    bool isMotionActivated = false);

    const std::string& type() const { return type_; }
    double intensityLux() const { return intensityLux_; }
    double colorTemperatureK() const { return colorTemperatureK_; }
    bool isMotionActivated() const { return isMotionActivated_; }

private:
    std::string type_;
    double intensityLux_;
    double colorTemperatureK_;
    bool isMotionActivated_;
};