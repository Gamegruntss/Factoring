#include "polynomial.h"

#ifndef FACTOR_H
#define FACTOR_H

class Factor
{
    public:

    Factor(Polynomial&);

    std::vector<double> roots(std::unordered_set<double>& possibleRoots);
    std::unordered_set<double> possibleRoots();

    private:

    Polynomial poly;
    std::vector<double> allRoots;
    std::unordered_map<size_t, std::unordered_set<size_t>> multiplicationTable;
    void loadMultiplicationTable();
    void roots(Polynomial&, std::unordered_set<double>&);
    
    

};


#endif