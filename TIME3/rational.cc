#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
    Rational ra{1, 6};
    Rational rc{0, 6};
    Rational test{ra + rc};
    test.show();

    return 0;
}
