#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
    Rational ra{1, 3};
    Rational rc{2, 4};

    // test for "+" operator
    Rational test{ra + rc};
    test.show();

    // test for "-" operator
    test = (rc - ra);
    test.show();

    // for "*" operator
    test = (test * ra);
    test.show();

    // test for "/" operator
    test = (test / ra);
    test.show();

    return 0;
}
