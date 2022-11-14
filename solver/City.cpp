//
// Created by misha on 12.11.2022.
//

#include "City.h"

bool City::checkIfFull() {
    for (auto& [coinsCountry, coinsNum]: coins) {
        if (coinsNum == 0) {
            full = false;
            return full;
        }
    }
    full = true;
    return full;
}

std::unique_ptr<City> City::createCity(Country* country, const std::vector<Country*>& countries) {
    std::unique_ptr<City> city = std::make_unique<City>();
    city->country = country;
    for (auto& curCountry: countries) {
        city->coins[curCountry] = 0;
    }
    city->coins[country] = 1'000'000;
    city->full = false;
    return city;
}

CoinChange City::getOutput() {
    CoinChange change = CoinChange();
    for (auto [country, curBalance]: coins) {
        change.addChange(country, curBalance / 1000);
    }
    return change;
}

void City::applyChange(const CoinChange& change) {
    for (auto [country, changeAmount]: change.getChanges()) {
        coins[country] = std::max<int64_t>(coins[country] + changeAmount, 0);
    }
}

CoinChange City::getSelfChange(uint32_t neighborsCount) {
    CoinChange change = CoinChange();
    for (auto [country, curBalance]: coins) {
        change.addChange(country, curBalance / 1000 * static_cast<int64_t>(neighborsCount) * -1);
    }
    return change;
}
