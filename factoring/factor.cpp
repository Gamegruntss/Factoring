#include "factor.h"

Factor::Factor(Polynomial& poly) : poly{poly} { }

std::vector<double> Factor::roots(std::unordered_set<double>& possibleRoots)
{
    std::vector<double> roots;
    double previousResult;
    double result;
    roots.reserve(possibleRoots.size());
    if(poly.termCount == 1) return roots;
    if(poly.termCount == 2) {roots.emplace_back(poly.coefficents.at(1) * -1);}

    for(double i: possibleRoots)
    {
        previousResult = 1;
        for (size_t j = 1; j < poly.termCount; ++j)
            previousResult = poly.coefficents.at(j)+ (previousResult * i);
            
        if(previousResult == 0) roots.emplace_back(i);
    }
    return roots;
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

    p.loadMultiplicationTable();
    q.loadMultiplicationTable();

    for(int i : p.factor(pInt))
        for(int j: q.factor(qInt))
            possibleRoots.emplace(i/j);

    return possibleRoots;
}
