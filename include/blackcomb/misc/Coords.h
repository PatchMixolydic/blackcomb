#ifndef CRAFTCLONE_COORDS_H
#define CRAFTCLONE_COORDS_H

#include <functional>

struct UVCoord {
    float u;
    float v;
};

struct UVRect {
    UVCoord botLeft;
    UVCoord topRight;
};

struct Point2 {
    float x;
    float y;
};

struct Point2i {
    int x;
    int y;
};

struct Point3i;

struct Point3 {
    float x;
    float y;
    float z;

    bool operator==(const Point3& other) const;
    bool operator==(const Point3i& other) const;
};

struct Point3i {
    int x;
    int y;
    int z;

    bool operator==(const Point3& other) const;
    bool operator==(const Point3i& other) const;
};

struct Color {
    int r;
    int g;
    int b;
    int a = 255;
};

namespace std {
    template <>
    struct hash<Point3> {
        std::size_t operator()(const Point3& k) const {
            return ((hash<float>()(k.x) ^ (hash<float>()(k.y) << 1)) >> 1) ^ (hash<float>()(k.z) << 1);
        }
    };

    template <>
    struct hash<Point3i> {
        std::size_t operator()(const Point3i& k) const {
            return ((hash<int>()(k.x) ^ (hash<int>()(k.y) << 1)) >> 1) ^ (hash<int>()(k.z) << 1);
        }
    };
}

#endif //CRAFTCLONE_COORDS_H
