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
    

};


#endif