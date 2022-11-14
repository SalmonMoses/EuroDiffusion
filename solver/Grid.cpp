//
// Created by misha on 12.11.2022.
//

#include "Grid.h"
#include "Country.h"

Grid::Grid(uint64_t width, uint64_t height, const std::vector<Country*>& countries) : width(width), height(height) {
    grid.resize(height);
    for (std::vector<std::unique_ptr<City>>& row: grid) {
        row.resize(width);
        std::fill(row.begin(), row.end(), nullptr);
    }
    for (auto country: countries) {
        initCountryOnMap(country, countries);
    }
}

void Grid::initCountryOnMap(Country* country, const std::vector<Country*>& countries) {
    Vector2 bottomLeft = country->getBottomLeft();
    Vector2 topRight = country->getTopRight();
    for (uint32_t y = bottomLeft.y - 1; y < topRight.y;
         ++y) { // yes, map is inverted in memory, but it is better to see it like this, imho
        for (uint32_t x = bottomLeft.x - 1; x < topRight.x; ++x) {
            grid[y][x] = City::createCity(country, countries);
            country->addCity(grid[y][x].get());
        }
    }
}

City* Grid::at(uint64_t x, uint64_t y) {
    if (x >= width || y >= height) { return nullptr; }
    return grid[y][x].get();
}

uint64_t Grid::getWidth() const {
    return width;
}

uint64_t Grid::getHeight() const {
    return height;
}
