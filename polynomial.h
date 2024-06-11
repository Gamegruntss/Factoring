#include <vector>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>
#include <math.h>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct Polynomial
{
    std::vector<int> coefficents;
    char var{};
    size_t termCount{coefficents.size()};
    
    friend std::ostream& operator<<(std::ostream&, const Polynomial&);

    std::unordered_set<int> factor(const int, std::unordered_map<size_t, std::unordered_set<size_t>>&) const;

    int at(const int);

};

#endif