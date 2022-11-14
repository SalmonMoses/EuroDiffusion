//
// Created by misha on 12.11.2022.
//

#include "Country.h"

Country::Country(const std::string& name, const Vector2& bottomLeft, const Vector2& topRight) : name(name),
                                                                                                bottomLeft(bottomLeft),
                                                                                                topRight(topRight),
                                                                                                full(false) {}

Country* Country::fromParsedCountry(const ParsedCountry& source) {
    auto* country = new Country(source.countryName, source.bottomLeft,
                                   source.topRight);
    return country;
}

bool Country::checkIfFull() {
    for (City* city: cities) {
        if (!city->isFull()) {
            if (!city->checkIfFull()) {
                full = false;
                return full;
            }
        }
    }
    full = true;
    return full;
}

const std::string& Country::getName() const {
    return name;
}

const Vector2& Country::getBottomLeft() const {
    return bottomLeft;
}

const Vector2& Country::getTopRight() const {
    return topRight;
}

void Country::addCity(City* city) {
    cities.emplace_back(city);
}
