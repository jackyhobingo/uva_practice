#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        vector<string> file;
        int max_len = 0;
        for (int i=0;i<60;i++)
            cout << "-";
        cout << endl;
        getchar();
        for (int i=0; i < n; i++) {
            string tmp;
            //getline(cin, tmp);
            cin >> tmp;
            file.push_back(tmp);
            if (max_len < tmp.length()){
                max_len = tmp.length(); 
            }
        }
        int R = 1+ (60 - max_len)/ (max_len + 2);
        sort(file.begin(), file.end());
        int r = n / R + (n % R > 0); 
        if (R > 0){
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < R; j++){
                if (i + j * r < n){
                    cout << file[i+j*r];
                    for(int k = 0;k < max_len - file[i + j * r].length() + 2;k++){
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
        } else {
            for (int i=0;i <n;i++) {
                cout << file[i] << endl;
            }
        }
        file.clear();
    }
}
