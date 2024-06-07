#include "factor.h"

Factor::Factor(Polynomial& poly) : poly{poly}
{
    loadMultiplicationTable();
}

std::vector<double> Factor::roots(std::unordered_set<double>& possibleRoots)
{
    roots(poly, possibleRoots);

    return allRoots;  
}

std::unordered_set<double> Factor::possibleRoots()
{
    std::unordered_set<double> possibleRoots;
    int qInt{poly.coefficents.at(0)}; 
    int pInt{poly.coefficents.at(poly.termCount - 1)};
    std::vector<int> qVal{qInt};
    std::vector<int> pVal{pInt};
    Polynomial q{qVal, 'x'};
    Polynomial p{pVal, 'x'};

    for(int i : p.factor(pInt, multiplicationTable))
        for(int j: q.factor(qInt, multiplicationTable))
            possibleRoots.emplace(i/j);

    return possibleRoots;
}

void Factor::loadMultiplicationTable()
{
    size_t product;

    for(size_t i = 1; i <= 200; ++i)
        for (size_t j = 1; j <= 200; ++j)
        {
            product = i*j;
            multiplicationTable[product].emplace(i);
            multiplicationTable[product].emplace(j);
        }

}

void Factor::roots(Polynomial& factored, std::unordered_set<double>& possibleRoots)
{
    std::vector<int> factoredCoefficients;
    double previousResult;
    double result;
    std::unordered_set<double> roots;
    
    if(factored.termCount == 1) return;
    if(factored.termCount == 2)
    {
        allRoots.emplace_back(factored.coefficents.at(1) * -1);
        return;
    }

    for(double i: possibleRoots)
    {
        previousResult = 1;
        for (size_t j = 1; j < factored.termCount; ++j)
            {
                factoredCoefficients.push_back(static_cast<int>(previousResult));
                previousResult = factored.coefficents.at(j)+ (previousResult * i);
            }
        if(previousResult == 0) 
        {
            allRoots.emplace_back(i);
            factoredCoefficients.resize(factored.termCount - 1);
            Polynomial p{factoredCoefficients,'x'};
            this->poly = p;
            roots = this->possibleRoots();
            Factor::roots(p, roots);
            return;
        }
        factoredCoefficients.clear();
    }
}
