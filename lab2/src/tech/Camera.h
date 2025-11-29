#pragma once
#include "spaces/Room.h"

class Camera {
public:
    Camera(Room* location, bool isRecording = false);
    
    Room* getLocation() const { return location_; }
    bool isRecording() const { return isRecording_; }

private:
    Room* location_;
    bool isRecording_;
};