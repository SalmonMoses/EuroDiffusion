#include <iostream>
#include <fstream>
#include <algorithm>
#include "parser/CaseParser.h"
#include "solver/DiffusionSolver.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please, specify input file!" << std::endl;
        return 1;
    }
    std::ifstream inputFileStream(argv[1]);
    CaseParser caseParser(inputFileStream);
    std::vector<ParsedCountry> countriesBuffer;
    DiffusionSolver solver;
    uint64_t caseCounter = 0;
    while (caseParser.parseNextCase(countriesBuffer)) {
        std::cout << "Case Number " << ++caseCounter << std::endl;
        std::vector<CountrySolution> solutions = solver.solve(countriesBuffer);
        std::sort(solutions.begin(), solutions.end());
        std::for_each(solutions.begin(), solutions.end(),
                      [](const CountrySolution& solution) { std::cout << solution << std::endl; });
        countriesBuffer.clear();
    }
    return 0;
}
