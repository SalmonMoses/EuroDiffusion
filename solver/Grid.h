//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_GRID_H
#define EURODIFFUSION_GRID_H


#include <cstdint>
#include <vector>
#include "Country.h"

class Grid {
public:
    Grid(uint64_t width, uint64_t height, const std::vector<Country*>& countries);

    City* at(uint64_t x, uint64_t y);

    uint64_t getWidth() const;

    uint64_t getHeight() const;

private:
    uint64_t width;
    uint64_t height;
    std::vector<std::vector<std::unique_ptr<City>>> grid;

    void initCountryOnMap(Country* country, const std::vector<Country*>& countries);
};


#endif //EURODIFFUSION_GRID_H
