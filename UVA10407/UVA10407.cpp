#include<iostream>
#include<algorithm>
using namespace std;

void computeMinMax(int arr[], int number, int &min_, int &max_) {
    min_ = arr[0];
    max_ = arr[0];
    for (int i = 1; i < number; i++) {
        if (min_ > arr[i]) {
            min_ = arr[i];
        } 
        if (max_ < arr[i]) {
            max_ = arr[i];
        }
    }
}

void minusMin(int arr[], int number, int &min_, int &max_) {
    for (int i = 0; i < number; i++) {
        arr[i] -= min_;
    }
    max_ -= min_;
}

int gcd(int a, int b) {
    if (b > a) {
        return gcd(b, a);
    }
    else if(b == 0){
        return a;
    }
    else {
        return gcd(b, a % b);
    }   
}

int findGCD(int arr[], int number, int max_) {
    int min_gcd = max_;
    for (int i = 0; i < number; i++) {
        min_gcd = gcd(min_gcd, arr[i]);
    }
    return min_gcd;
}

int main()
{
    int n[1000];
    while (true) {
        int i;
        for (i = 0; i <= 1000; i++) {
            cin >> n[i];
            if (n[i] == 0) {
                break;
            }
        }
        if (n[0] == 0) {
            break;
        }
        int number = i;
        int min_;
        int max_;
        computeMinMax(n, number, min_, max_);
        minusMin(n, number, min_, max_);
        int gcd = findGCD(n, number, max_);
        cout << gcd << endl;
    }

    return 0;
}
