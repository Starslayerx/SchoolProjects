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

    Retangle r{5, 6};
    r.show();

    cout << "Test for Ploymorphism:" << endl;
    Shape * s;
    s = &c;
    s->show();
    s = &t;
    s->show();
    s = &r;
    s->show();
    return 0;
}
