#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "MyWorld.h"

int main()
{
    char ch[] = "This is myworld";
    int n = sizeof(ch) / sizeof(char);
    MyWorld mine(ch, n);
    
    mine.show();
    cout << endl;
    for (int i = 0; i < 3; ++i)
        mine.stest();
    cout << endl;
    


    return 0;
}
