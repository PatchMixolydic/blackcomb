
#include <blackcomb/misc/Coords.h>

#include "../../include/blackcomb/misc/Coords.h"


bool UVCoord::operator==(const UVCoord &other) const {
    return u == other.u && v == other.v;
}

bool UVRect::operator==(const UVRect &other) const {
    return botLeft == other.botLeft && topRight == other.topRight;
}

bool Point2::operator==(const Point2 &other) const {
    return x == other.x && y == other.y;
}

bool Point2::operator==(const Point2i &other) const {
    return x == other.x && y == other.y;
}

bool Point2i::operator==(const Point2 &other) const {
    return x == other.x && y == other.y;
}

bool Point2i::operator==(const Point2i &other) const {
    return x == other.x && y == other.y;
}

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

bool Color::operator==(const Color &other) const {
    return r == other.r && g == other.g && b == other.b;
}
