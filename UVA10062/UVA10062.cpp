#include<iostream>
#include<cstring>

#define MAX_SIZE 1001

using namespace std;

int main() {
    char str[MAX_SIZE];
    bool isFirstInput = true;

    while (cin.getline(str, MAX_SIZE)) {
        
        int len = strlen(str);
        int count[128];
        int pair[128][2];
        memset(count, 0, sizeof(int) * 128);
        memset(pair, 0, sizeof(int) * 128 * 2);

        for (int i = 0; i <= len; i++) {
            count[(int)str[i]] ++;
        }     

        int j = 0;
        for (int i = 127; i > 31; i--) {
            if (count[i] != 0) {
                pair[j][0] = i;
                pair[j][1] = count[i];
                j++;
            }
        }
    
        // sort
        for (int i = 0; i < j - 1; i++) {
            for (int k = 0; k < j - 1 - i; k++) {
                if (pair[k][1] > pair[k+1][1]) {
                    swap(pair[k][0], pair[k+1][0]);
                    swap(pair[k][1], pair[k+1][1]);
                }
            }
        }
        
        
        // print
        if (!isFirstInput) {
            cout << endl;
        }
        for (int i = 0; i < j; i++) {
            cout << pair[i][0] << " " << pair[i][1] << endl;
        }

        isFirstInput = false;
    }
    return 0;
}
