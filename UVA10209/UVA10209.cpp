#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 2*acos(0.0)
using namespace std;

int main()
{
    double a, x, y, z;
    double square, sector, bullet;
    while (cin >> a) {
        square = a * a;
        sector = a * a * PI * 0.25;
        bullet = (1.0 / 3.0 * PI - sqrt(3.0) / 4.0) * a * a;
        z = square - 2 * sector + bullet;
        y = sector - bullet - z;
        x = square - 4 * (y + z);
        cout << setprecision(3) << fixed << x << " " << y * 4 << " " << z * 4 << endl;
   
    }
   

}
