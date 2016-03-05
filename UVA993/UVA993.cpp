#include <iostream>
#include <cstring>
using namespace std;

int FactorDecomposition[10] = {0,0,0,0,0,0,0,0,0,0};
int main()
{
    int n;
    cin >> n;
    while (n--) {
        int number, remain;
        int can = true;
        cin >> number;
        remain = number;
        memset(FactorDecomposition, 0, sizeof(FactorDecomposition));
        if (remain > 0) {
            for (int i = 9; i >= 2; i--) {
                if (remain % i == 0) {
                    FactorDecomposition[i] += 1;
                    remain /= i;
                    i+=1;
                }

            }
            if (remain > 10) {
                can = false;
            }
        }
        if (!can) {
            cout << -1 << endl;
        }
        else if (number == 1) {
            cout << 1 << endl;
        } 
        else if (number == 0) {
            cout << 10 << endl;
        }
        else {
            
            for (int i = 2; i <= 9;i++) {
                while(FactorDecomposition[i]--) {
                    cout << i;
                }
            }
            cout << endl;

        }



    }
}
