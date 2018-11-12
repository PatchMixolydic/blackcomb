#include "../../include/blackcomb/misc/Coords.h"

bool Point3::operator==(const Point3 &other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Point3::operator==(const Point3i &other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Point3i::operator==(const Point3i &other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Point3i::operator==(const Point3 &other) const {
    return x == other.x && y == other.y && z == other.z;
}
