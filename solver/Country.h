//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_COUNTRY_H
#define EURODIFFUSION_COUNTRY_H


#include <vector>
#include "../parser/ParsedCountry.h"
#include "City.h"

class Country {
public:
    Country(const std::string& name, const Vector2& bottomLeft, const Vector2& topRight);

    static Country* fromParsedCountry(const ParsedCountry& source);

    [[nodiscard]] inline bool isFull() const { return full; }

    bool checkIfFull();
    void addCity(City* city);

    const std::string& getName() const;

    const Vector2& getBottomLeft() const;

    const Vector2& getTopRight() const;

private:
    std::string name;
    Vector2 bottomLeft;
    Vector2 topRight;
    bool full = false;
    std::vector<City*> cities;
};


#endif //EURODIFFUSION_COUNTRY_H
