#include<iostream>
#include<iomanip>
#include<cmath>

#define PI (2 * acos(0.0))
#define deg_to_min(a) ((a) < 180 ? ((a) / 180.0 * PI): ((360 - a) / 180.0 * PI))
#define arc_distance(s,a) (((s) + 6440) * (a))
#define chord_distance(s,a) (((s) + 6440) * 2 * sin(a / 2))


using namespace std;

int main() {
    double s, a;
    char str[4];
    cout << setprecision(6) << fixed;
    while (cin >> s >> a >> str) {
        double arc, chord;
        if (str[0] == 'd') {
            a *= 60.0;
        }
        cout << arc_distance(s, deg_to_min(a / 60.0)) << " ";
        cout << chord_distance(s, deg_to_min(a / 60.0)) << endl;
    }
}
