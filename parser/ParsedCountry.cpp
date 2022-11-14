//
// Created by misha on 12.11.2022.
//

#include <string>
#include <utility>
#include "../Vector2.h"
#include "ParsedCountry.h"

ParsedCountry::ParsedCountry(std::string countryName,
                             const Vector2& bottomLeft, const Vector2& topRight) : countryName(std::move(countryName)),
                                                                                   bottomLeft(bottomLeft),
                                                                                   topRight(topRight) {}
