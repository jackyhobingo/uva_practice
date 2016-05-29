#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long x, y;
    while(cin >> x >> y) {
        if(x > y) 
            cout << x - y << endl;
        else
            cout << y - x << endl;
    }
    return 0;
}
