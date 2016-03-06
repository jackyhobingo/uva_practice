#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdlib>
using namespace std;
int gcd (int a, int b) {
    while (b) {
        swap(a %= b, b);
    }
    return a;
}


int main()
{   
    
    string s;
    while (cin >> s, s!="0") {
        s = s.substr(0,s.size()-3).substr(2);
        int ansu, ansd = INT_MAX, n = s.size();

        for (int k = 1; k <= n; k ++) {
            int u = atoi(s.c_str()) - atoi(s.substr(0,n-k).c_str());
            int d = pow(10, n) - pow(10,n-k);
            int g = gcd(u, d);
            u/=g;
            d/=g;
            if (d < ansd) {
                ansd = d;
                ansu = u;
            }
        }
        cout << ansu << '/' << ansd << endl;
    }
    return 0;
}
