#pragma once

#include "Room.h"

class StorageRoom : public Room {
public:
    StorageRoom(std::string name, double climateControlTempC = 20.0);

    double climateControlTempC() const { return climateControlTempC_; }
    void adjustTemperature(double temp);

    std::string getDescription() const override;

private:
    double climateControlTempC_;
};