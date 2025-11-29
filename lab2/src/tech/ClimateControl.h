#pragma once

class ClimateControl {
public:
    ClimateControl(double targetTempC, double humidityPercent);
    
    double targetTempC() const { return targetTempC_; }
    double humidityPercent() const { return humidityPercent_; }

private:
    double targetTempC_;
    double humidityPercent_;
};