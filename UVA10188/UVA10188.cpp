#include <iostream>
#include <cstring>
using namespace std;

char str1number[100000];
char str2number[100000];
char str1[100000];
char str2[100000];
char buffer[1000];
int main()
{
    int n, m;
    int time = 0;
    while (true) {
        time++;
        cin >> n;
        if (n == 0) {
            break;
        }

        cin.getline(buffer, 2); 
        
        str1[0] = '\0';
        for (int i = 0; i < n; i++) {
            buffer[0] = '\0';
            cin.getline(buffer, 1000);
            strcat(str1, buffer);
            
        }
        cin >> m;
        cin.getline(buffer, 2); 
        
        str2[0] = '\0';
        for (int i = 0; i < m; i++) {
            buffer[0] = '\0';
            cin.getline(buffer, 1000);
            strcat(str2, buffer);
        }
        cout << "Run #" << time << ": ";
        if (strcmp(str1, str2) == 0) {
            if (m == n) {
                cout << "Accepted" << endl;
            } else { 
                cout << "Presentation Error" << endl;
            } 
            continue;    
        }
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int k = 0;
        for (int j = 0; j < len1; j++) {
           if (str1[j] <= '9' && str1[j] >= '0') {
               str1number[k] = str1[j];
               k++;
           }
        }
        str1number[k] = '\0';
        k = 0;
        for (int j = 0; j < len2; j++) {
            if (str2[j] <= '9' && str2[j] >= '0') {
                str2number[k] = str2[j];
                k++;
            }
        }
        str2number[k] = '\0';
        if (strcmp(str1number, str2number) != 0) {
            cout << "Wrong Answer" << endl;
        } else {
            cout << "Presentation Error" << endl;
        }
    }

    return 0;

}

