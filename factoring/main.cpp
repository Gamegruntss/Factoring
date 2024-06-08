#include "factor.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> coefficients{1,4,-62,-200,1009,2356,-3828,-5040};
    char var = 'x';
    Polynomial p{coefficients, var};
    Factor f(p);
    auto pos = f.possibleRoots();
    for(auto i: f.roots(pos))
    {
        std::cout << "(" << p.var;
        if (i < 0) {std::cout << " + " << i * -1 << ") ";}
        else {std::cout << " - " << i << ") ";}
    }
    std::cout << std::endl;

    std::cout << p.at(2) << std::endl;
    return 0;
}
