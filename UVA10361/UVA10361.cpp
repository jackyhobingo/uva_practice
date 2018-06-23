#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    string firstLine;
    string secondLine;
    cin >> n;
    char c = getchar();
    while(n--){
        getline(cin, firstLine);
        getline(cin, secondLine);
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string se2;
        bool islt = false;
        int l = firstLine.length();
        int state = 0;
        for(int i = 0; i < l; i++) {
            if(state == 0 && firstLine[i] != '<') 
                s1 += firstLine[i];
            else if(state == 0) {
                state = 1; continue;
            }
            if (state == 1 && firstLine[i] != '>') {
                s2 += firstLine[i];
            } else if (state == 1) {
                state = 2; continue;
            } 
            if (state == 2 && firstLine[i] != '<') {
                s3 += firstLine[i];
            } else if (state == 2) {
                state = 3; continue;
            }  
            if (state == 3 && firstLine[i] != '>') {
                s4 += firstLine[i];
            } else if (state == 3) {
                state = 4; continue;
            }  
            if (state == 4) {
                s5 += firstLine[i];
            }
        }
        for (int i = 0; i < secondLine.length(); i++) {
            if(secondLine[i]!= '.')
                se2 += secondLine[i];
        }
        cout << s1 << s2 << s3 << s4 << s5 << endl;
        cout << se2 << s4 << s3 << s2 << s5 << endl;
    }
}
