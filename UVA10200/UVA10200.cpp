#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


int primes[10001];
int computedNumber = 39;
void isPrime(int n) {
    int p = n * n + n + 41;
    for (int i = 2; i * i <= p; i++) {
        if ( p % i == 0) {
            primes[n] = 0;
            return;
        }
    } 
    primes[n] = 1;
}


int main()
{
    memset(primes, 0, sizeof(primes));
    for (int i = 0; i < 40; i++) {
        primes[i] = 1;
    }

    int a, b;
    while (cin >> a >> b) {
        if (a > b) {
            swap(a, b);
        }
        if (b > computedNumber) {
            for (int i = computedNumber + 1; i <= b; i++) {
                isPrime(i);           
            }
            computedNumber = b;
        } 
        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += primes[i];
        }
        int ans;
        cout <<  setprecision(2) << fixed << (double)100.0* sum/(b-a+1) + 0.00001  << endl;

    }



}
