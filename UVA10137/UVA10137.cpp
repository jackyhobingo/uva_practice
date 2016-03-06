#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        if (n==0)
            break;
        int moneys[n];
        int a, b;
        int sum = 0;
        char dot;
        for (int i = 0; i < n; i++) {
            cin >> a >> dot >> b;
            moneys[i] = 100 * a + b;
            sum += moneys[i];
        }
        double avg = (double)sum / (double)n;
        double diff1 = 0, diff2 = 0;
        for (int i = 0; i < n; i++) {
            if (avg > moneys[i]){
                diff1 += floor(avg - moneys[i]);
            }
            else {
                diff2 += floor(moneys[i] - avg);
            }
        }
        cout << "$" << setprecision(2) << fixed << max(diff1, diff2) / 100 << endl;;

    }
}
