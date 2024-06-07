#include "factor.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> coefficients{1,9,26,24};
    char var = 'x';
    Polynomial p{coefficients, var};
    //std::cout << p << std::endl;
    Factor f(p);
    auto pos = f.possibleRoots();
    for(auto i: f.roots(pos))
        std::cout << "(" << p.var << " + " << i * -1 << ")" << std::endl;
    
    return 0;
}
