#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double L, W;
    
    while (cin >> L >> W) {
        double max_ = (L+W - sqrt(L*L-L*W+W*W))/6.0 + 0.000001;
        double min_ = min(L,W) * 0.5 + 0.000001;
        cout << setprecision(3) << fixed << max_ << " "<<0.000 << " " << min_ << endl;;


    }


}
