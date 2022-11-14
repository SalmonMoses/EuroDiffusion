//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_PARSEDCOUNTRY_H
#define EURODIFFUSION_PARSEDCOUNTRY_H

#include <string>
#include "../Vector2.h"

struct ParsedCountry {
    ParsedCountry(std::string countryName, const Vector2& bottomLeft, const Vector2& topRight);

    std::string countryName;
    Vector2 bottomLeft;
    Vector2 topRight;
};

#endif //EURODIFFUSION_PARSEDCOUNTRY_H
