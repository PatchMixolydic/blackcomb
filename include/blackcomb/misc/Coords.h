#ifndef CRAFTCLONE_COORDS_H
#define CRAFTCLONE_COORDS_H

#include <functional>

struct UVCoord {
    bool operator==(const UVCoord& other) const;
    float u;
    float v;
};

struct UVRect {
    bool operator==(const UVRect& other) const;
    UVCoord botLeft;
    UVCoord topRight;
};

struct Point2i;

struct Point2f {
    bool operator==(const Point2f& other) const;
    bool operator==(const Point2i& other) const;
    float x;
    float y;
};

struct Point2i {
    bool operator==(const Point2f& other) const;
    bool operator==(const Point2i& other) const;
    int x;
    int y;
};

struct Point3i;

struct Point3f {
    bool operator==(const Point3f& other) const;
    bool operator==(const Point3i& other) const;
    float x;
    float y;
    float z;
};

struct Point3i {
    bool operator==(const Point3f& other) const;
    bool operator==(const Point3i& other) const;
    int x;
    int y;
    int z;
};

struct Color {
    bool operator==(const Color& other) const;
    int r;
    int g;
    int b;
    int a = 255;
};

namespace std {
    template <>
    struct hash<Point3f> {
        std::size_t operator()(const Point3f& k) const {
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
