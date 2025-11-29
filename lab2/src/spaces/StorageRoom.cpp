#include "StorageRoom.h"
#include <iostream>

StorageRoom::StorageRoom(std::string name, double temp)
    : Room(std::move(name)), climateControlTempC_(temp) {}

void StorageRoom::adjustTemperature(double temp) {
    climateControlTempC_ = temp;
}

std::string StorageRoom::getDescription() const {
    return "StorageRoom '" + name() + "': temperature " +
           std::to_string(climateControlTempC_) + "°C";
}