//
// Created by misha on 12.11.2022.
//

#include "CaseParser.h"

CaseParser::CaseParser(std::istream& sourceStream) : sourceStream(sourceStream) {}

bool CaseParser::parseNextCase(std::vector<ParsedCountry>& outParsedCountries) {
    size_t countriesNumber;
    sourceStream >> countriesNumber;
    if (countriesNumber == 0) {
        return false;
    }
    for (size_t i = 0; i < countriesNumber; ++i) {
        uint64_t xl, yl, xh, yh;
        std::string countryName;
        sourceStream >> countryName >> xl >> yl >> xh >> yh;
        const Vector2& bottomLeft = Vector2(xl, yl);
        const Vector2& topRight = Vector2(xh, yh);
        outParsedCountries.emplace_back(countryName, bottomLeft, topRight);
    }
    return true;
}
