//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_COINCHANGE_H
#define EURODIFFUSION_COINCHANGE_H


#include <cstdint>
#include <map>

class Country;

class CoinChange {
public:
    CoinChange merge(const CoinChange& rhs);
    void addChange(Country* country, int64_t change);

    [[nodiscard]] const std::map<Country*, int64_t>& getChanges() const;

private:
    std::map<Country*, int64_t> changes;
};


#endif //EURODIFFUSION_COINCHANGE_H
