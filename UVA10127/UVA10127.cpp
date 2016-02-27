#include<iostream>

using namespace std;

int main()
{
    int N;
    while(cin >> N){
        int i = 1;
        int remain = i % N;
        while (remain != 0) {
            remain = (remain * 10 + 1) % N;
            i++;
        }
        cout << i << endl;
    }
}
