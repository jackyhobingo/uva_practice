#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n;

    while (cin >> n) {
        int upbound = pow(10, n/2);
        
        for (int i = 0; i < upbound; i++) {
            int pw = i*i;
            int r = pw % upbound;
            int q = pw / upbound;
            if( pw == (r + q) * (r + q) ) {
                    cout << setw(n) << setfill('0') << pw  << endl;           
            }
        } 
    }  
}
