#pragma once

namespace luna {

struct CieColorCoordinates {
    float u = 0.0f;
    float v = 0.0f;
};

struct ColorSpace {
    CieColorCoordinates white;
    CieColorCoordinates red;
    CieColorCoordinates green;
    CieColorCoordinates blue;
};

}
