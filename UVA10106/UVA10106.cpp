#include<iostream>
#include<cstring>
using namespace std;


int main()
{
    int bigNumber[2][251];
    char bigNumberInput[252]; 
    int bigNumberAns[502];
    int len[2];
    while (!cin.eof()){
        memset(bigNumber[0], 0, sizeof(bigNumber[0]));
        memset(bigNumber[1], 0, sizeof(bigNumber[1]));
        memset(bigNumberAns, 0, sizeof(bigNumberAns));
        bool input = true;
        
        for (int i = 0; i < 2; i++) {
            cin.getline(bigNumberInput, 252);
            len[i] = strlen(bigNumberInput);
            if (len[i] == 0) {
                input = false;
                break;
            }
            for (int j = 0; j < len[i]; j++) {
                bigNumber[i][len[i] - 1 - j] =  bigNumberInput[j] - '0';
            }
        }
        if (!input) {
            break;
        }
        
        for (int i = 0; i < len[0]; i++) {
            for (int j = 0; j < len[1]; j++) {
                bigNumberAns[i+j] += bigNumber[0][i] * bigNumber[1][j];
            }
        }
        for (int i = 0; i <= len[0] + len[1] - 2; i++) {
            bigNumberAns[i+1] += bigNumberAns[i] / 10;
            bigNumberAns[i] = bigNumberAns[i] % 10;
        }
        
        bool isZero = true;
        for (int i = len[0] + len[1] - 1; i >= 0;i--) {
            if(bigNumberAns[i] != 0) {
                isZero = false;
            }   
            if(isZero) {
                cout << bigNumberAns[i];
            }
        }

        if(isZero) {
            cout << 0;
        }

        cout << endl;
    }
}
