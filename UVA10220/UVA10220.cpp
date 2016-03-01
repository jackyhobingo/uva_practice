#include<iostream>
#include<cstring>
using namespace std;

void int_multiply_bigNumber(int n, int bigNumber[], int *len) 
{
    for (int i = 0; i < *len ;i++) {
        bigNumber[i] *= n;
    }
    for (int i = 0; i < *len + 3; i++) {
        bigNumber[i+1] += bigNumber[i] / 10;
        bigNumber[i] %= 10;
    }
    if (bigNumber[*len+2] != 0) {
        *len += 3;
    }
    else if(bigNumber[*len+1] != 0) {
        *len += 2;
    }
    else if (bigNumber[*len] != 0) {
        *len += 1;
    }
    
}
int sum_of_bit(int bigNumber[], int len) {
    int ans = 0;
    for (int i = 0; i < len; i++) {
        ans += bigNumber[i];
    }
    return ans;

}

int main()
{
    int n;
    int bigNumber[3000];
    while (cin >> n) {
        int len = 1;
        memset(bigNumber, 0, sizeof(bigNumber));
        bigNumber[0] = 1;
        while (n > 1) {
            int_multiply_bigNumber(n, bigNumber, &len);
            n--;
        }
        cout <<  sum_of_bit(bigNumber, len) << endl;
    }
    return 0;
}
