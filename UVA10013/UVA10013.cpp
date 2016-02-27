#include<iostream>

using namespace std;

int main()
{
    int n;
    bool first = true;
    cin >> n;
    while (n--) {
        int number;
        if (!first) {
            cout << endl;
        }
        cin >> number;
        int big_number[number + 1];
        for (int i = number - 1; i >= 0; i--) {
            int a,b;
            cin >> a >> b;
            big_number[i] = a + b;
        }
        big_number[number] = 0;
        for (int i = 0; i < number; i++) {
            big_number[i+1] += big_number[i] / 10;
            big_number[i] %= 10;
        }
        if (big_number[number] != 0) {
            cout << big_number[number];
        }
        for (int i = number - 1; i >= 0; i--) {
            cout << big_number[i];
        }
        cout << endl;
        first = false;
    }


}
