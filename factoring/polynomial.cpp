#include "polynomial.h"

std::ostream& operator<<(std::ostream& out, const Polynomial& p)
{
    size_t exponent;
    for (size_t i = 0; i < p.termCount; ++i)
    {
        exponent = p.termCount - i - 1;
        out << p.coefficents.at(i) << p.var << "^" << exponent << " ";
    }

    return out;
}

std::unordered_set<int> Polynomial::factor(const int number) const
{
    std::unordered_set<int> factors;
    int posNumber;
    if(number < 0) {posNumber = number * -1;}
    else {posNumber = number;}
    std::unordered_map<size_t, std::unordered_set<size_t>> map{this->multiplicationTable};
    std::unordered_set<size_t> posFactors{map[number]};
    for(size_t i: posFactors)
    {
        factors.emplace(i);
        factors.emplace(i * -1);
    }    
    return factors;
}

void Polynomial::loadMultiplicationTable()
{
    std::unordered_set<size_t> factors;
    size_t product;

    for(size_t i = 1; i <= 20; ++i)
        for (size_t j = 1; j <= 20; ++j)
        {
            product = i*j;
            multiplicationTable[product].emplace(i);
            multiplicationTable[product].emplace(j);
        }
        
}