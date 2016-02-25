#include<iostream>

using namespace std;

bool prime[1000001];

bool isPrime(int);
int reversing(int);
void build_prime();

int main() {
    build_prime();
    int N;
    while (cin >> N) {
        if (isPrime(N)) {
            int reverse = reversing(N);
            if (reverse != N && isPrime(reverse)) {
                cout << N << " is emirp." << endl;
            }
            else {
                cout << N << " is prime." << endl;
            }
        }
        else {
            cout << N << " is not prime." << endl;
        }
    }
}

void build_prime() {
    
    for (int i = 2; i < 1000001; i++) {
        prime[i] = true;
    }
    for (int i = 2; i <= 1000; i++) {
        int t = i + i;
        while (t < 1000001) {
            prime[t] = false;
            t += i;
        }
    }
}

bool isPrime(int N) {
    return prime[N];
}

int reversing(int N) {
    
    int new_N = 0;
    while (N > 0) {
        new_N *= 10;
        new_N += N % 10;
        N /= 10;
    }
    return new_N;
}
