#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#include "Shape.h"


int main()
{
    Circle c{5};
    c.show();

    Triangle t{1, 2, 3}; 
    Triangle t2{3, 4, 5};
    t2.show();

    return 0;
}
