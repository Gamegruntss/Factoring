#include "factor.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> coefficients{1,-3,-23,51,94,-120};
    char var = 'x';
    Polynomial p{coefficients, var};
    Factor f(p);
    auto pos = f.possibleRoots();
    for(auto i: f.roots(pos))
        std::cout << "(" << p.var << " + " << i * -1 << ") ";
    
    return 0;
}
