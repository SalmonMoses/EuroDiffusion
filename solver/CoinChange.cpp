//
// Created by misha on 12.11.2022.
//

#include "CoinChange.h"

const std::map<Country*, int64_t>& CoinChange::getChanges() const {
    return changes;
}

CoinChange CoinChange::merge(const CoinChange& rhs) {
    CoinChange merged;
    for (auto [country, change]: changes) {
        merged.changes[country] = change;
    }
    for (auto [country, change]: rhs.changes) {
        merged.addChange(country, change);
    }
    return merged;
}

void CoinChange::addChange(Country* country, int64_t change) {
    if (!changes.contains(country)) {
        changes[country] = change;
    } else {
        changes[country] += change;
    }
}
