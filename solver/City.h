//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_CITY_H
#define EURODIFFUSION_CITY_H


#include <map>
#include <memory>
#include <vector>
#include "CoinChange.h"

class Country;

class City {
public:
    static std::unique_ptr<City> createCity(Country* country, const std::vector<Country*>& countries);

    [[nodiscard]] inline bool isFull() const { return full; }

    bool checkIfFull();

    CoinChange getOutput();
    CoinChange getSelfChange(uint32_t neighborsCount);
    void applyChange(const CoinChange& change);

private:
    Country* country;
    bool full = false;
    std::map<Country*, int64_t> coins;
};


#endif //EURODIFFUSION_CITY_H
