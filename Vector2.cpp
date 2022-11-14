//
// Created by misha on 12.11.2022.
//

#include "Vector2.h"

Vector2::Vector2(uint64_t x, uint64_t y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& os, const Vector2& vector2) {
    os << "(" << vector2.x << ", " << vector2.y << ")";
    return os;
}
