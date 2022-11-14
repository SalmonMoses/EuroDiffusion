//
// Created by misha on 12.11.2022.
//

#include "DiffusionSolver.h"
#include <algorithm>
#include <iostream>

DiffusionSolver::DiffusionSolver() = default;

DiffusionSolver::~DiffusionSolver() {
    for (Country* country: countries) {
        delete country;
    }
    delete grid;
}

std::vector<CountrySolution> DiffusionSolver::solve(const std::vector<ParsedCountry>& parsedCountries) {
    clear();
    if (parsedCountries.empty()) {
        return {};
    }
    if (parsedCountries.size() == 1) {
        return { CountrySolution(parsedCountries[0].countryName, 0) };
    }
    std::transform(parsedCountries.cbegin(), parsedCountries.cend(),
                   std::back_inserter(countries),
                   &Country::fromParsedCountry);
    uint64_t maxX = 0;
    uint64_t maxY = 0;
    for (auto& country: countries) {
        Vector2 topRight = country->getTopRight();
        maxX = std::max(maxX, topRight.x);
        maxY = std::max(maxY, topRight.y);
    }
    grid = new Grid(maxX, maxY, countries);
    while (!shouldEnd()) {
        nextIteration();
    }
    return countrySolutions;
}

void DiffusionSolver::nextIteration() {
    if (!currentStepChanges.empty()) {
        currentStepChanges.clear();
    }
    currentIteration++;
    for (uint64_t y = 0; y < grid->getHeight(); ++y) {
        for (uint64_t x = 0; x < grid->getWidth(); ++x) {
            calculateCity(x, y);
        }
    }
    for (auto& [city, change]: currentStepChanges) {
        city->applyChange(currentStepChanges[city]);
    }
    checkNewFullCountries();
}

void DiffusionSolver::checkNewFullCountries() {
    for (Country* country: countries) {
        if (country->isFull()) { continue; }
        else if (country->checkIfFull()) {
            countrySolutions.emplace_back(country->getName(), currentIteration);
        }
    }
}

bool DiffusionSolver::shouldEnd() {
    return std::ranges::all_of(countries, &Country::isFull);
}

void DiffusionSolver::calculateCity(uint64_t x, uint64_t y) {
    City* city = grid->at(x, y);
    if (!city) { return; }

    CoinChange cityChange = city->getOutput();
    uint32_t neighborsCount = 0;
    if (City* north = grid->at(x, y + 1)) {
        addChangeToCity(north, cityChange);
        neighborsCount++;
    }
    if (City* south = grid->at(x, y - 1)) {
        addChangeToCity(south, cityChange);
        neighborsCount++;
    }
    if (City* east = grid->at(x + 1, y)) {
        addChangeToCity(east, cityChange);
        neighborsCount++;
    }
    if (City* west = grid->at(x - 1, y)) {
        addChangeToCity(west, cityChange);
        neighborsCount++;
    }

    addChangeToCity(city, city->getSelfChange(neighborsCount));
}

void DiffusionSolver::clear() {
    for (Country* country: countries) {
        delete country;
    }
    countries.clear();
    countrySolutions.clear();
    currentStepChanges.erase(currentStepChanges.begin(), currentStepChanges.end());
    currentIteration = 0;
}

void DiffusionSolver::addChangeToCity(City* city, const CoinChange& change) {
    if (currentStepChanges.contains(city)) {
        currentStepChanges[city] = currentStepChanges[city].merge(change);
    } else {
        currentStepChanges[city] = change;
    }
}
