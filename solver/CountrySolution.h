//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_COUNTRYSOLUTION_H
#define EURODIFFUSION_COUNTRYSOLUTION_H


#include <string>
#include <ostream>

struct CountrySolution {
    CountrySolution(const std::string& countryName, uint64_t daysToComplete);

    bool operator<(const CountrySolution& rhs) const;

    bool operator>(const CountrySolution& rhs) const;

    bool operator<=(const CountrySolution& rhs) const;

    bool operator>=(const CountrySolution& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const CountrySolution& solution);

    std::string countryName;
    uint64_t daysToComplete;
};


#endif //EURODIFFUSION_COUNTRYSOLUTION_H
