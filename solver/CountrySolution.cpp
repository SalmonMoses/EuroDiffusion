//
// Created by misha on 12.11.2022.
//

#include "CountrySolution.h"

#include <utility>

CountrySolution::CountrySolution(const std::string& countryName, uint64_t daysToComplete)
        : countryName(countryName),
          daysToComplete(daysToComplete) {}

bool CountrySolution::operator<(const CountrySolution& rhs) const {
    return std::tie(daysToComplete, countryName) < std::tie(daysToComplete, countryName);
}

bool CountrySolution::operator>(const CountrySolution& rhs) const {
    return rhs < *this;
}

bool CountrySolution::operator<=(const CountrySolution& rhs) const {
    return !(rhs < *this);
}

bool CountrySolution::operator>=(const CountrySolution& rhs) const {
    return !(*this < rhs);
}

std::ostream& operator<<(std::ostream& os, const CountrySolution& solution) {
    os << solution.countryName << " " << solution.daysToComplete;
    return os;
}
