#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#include "MyWorld.h"

int main()
{
    char ch[] = "minecraft";
    int n = sizeof(ch) / sizeof(char);
    MyWorld mine(ch, n);
    
    // test
    mine.show();
    cout << endl;

    cout << "Static number test: " << endl;
    for (int i = 0; i < 3; ++i)
        mine.stest();
    cout << endl;
    
    // sentence
    vector <MyWorld> sentence;

    char t1[] = "This ";
    MyWorld a(t1, sizeof(t1) / sizeof(char));
    sentence.push_back(a);

    char t2[] = "is ";
    MyWorld b(t2, sizeof(t2) / sizeof(char));
    sentence.push_back(b);

    sentence.push_back(mine);

    cout << "Sentence test: " << endl;
    for (auto &t : sentence)
    {
        t.single();
        cout << " ";
    }
    cout << endl;
    return 0;
}
