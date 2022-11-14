//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_VECTOR2_H
#define EURODIFFUSION_VECTOR2_H


#include <cstdint>
#include <ostream>

struct Vector2 {
    Vector2(uint64_t x, uint64_t y);

    friend std::ostream& operator<<(std::ostream& os, const Vector2& vector2);

    uint64_t x;
    uint64_t y;
};


#endif //EURODIFFUSION_VECTOR2_H
