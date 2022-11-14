//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_DIFFUSIONSOLVER_H
#define EURODIFFUSION_DIFFUSIONSOLVER_H


#include <vector>
#include "CountrySolution.h"
#include "../parser/ParsedCountry.h"
#include "Country.h"
#include "Grid.h"

class DiffusionSolver {
public:
    DiffusionSolver();
    virtual ~DiffusionSolver();

    std::vector<CountrySolution> solve(const std::vector<ParsedCountry>& parsedCountries);

private:
    std::vector<Country*> countries;
    std::vector<CountrySolution> countrySolutions;
    std::map<City*, CoinChange> currentStepChanges;
    Grid* grid = nullptr;
    uint64_t currentIteration = 0;

    void nextIteration();
    void checkNewFullCountries();
    bool shouldEnd();

    void calculateCity(uint64_t x, uint64_t y);
    void addChangeToCity(City* city, const CoinChange& change);

    void clear();
};


#endif //EURODIFFUSION_DIFFUSIONSOLVER_H
