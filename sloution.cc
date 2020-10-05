#include <iostream>
#include <vector>
#include <map>
#include <string>
using std::map;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
#include "sloution.h"

int main()
{
    int a, b;
    Sloution re;
    cin >> a >> b;

    cout << re.sloution(a, b) << endl;

    return 0;
}
