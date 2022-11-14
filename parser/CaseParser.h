//
// Created by misha on 12.11.2022.
//

#ifndef EURODIFFUSION_CASEPARSER_H
#define EURODIFFUSION_CASEPARSER_H

#include <istream>
#include <vector>
#include "ParsedCountry.h"

class CaseParser {
public:
    explicit CaseParser(std::istream& sourceStream);

    [[nodiscard]] bool parseNextCase(std::vector<ParsedCountry>& outParsedCountries);

private:
    std::istream& sourceStream;
};


#endif //EURODIFFUSION_CASEPARSER_H
