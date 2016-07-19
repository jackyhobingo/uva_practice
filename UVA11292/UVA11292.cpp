#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, m, x;
    while(cin >> n >> m) {
        if (!n && !m) {
            break;
        }
        int t_n = n;
        int t_m = m;
        int x[n];
        int y[m];

        while(t_n--){
            cin >> x[t_n]; 
        }
        while(t_m--){
            cin >> y[t_m]; 
        }
        sort(x, x+n);
        sort(y, y+m);

        int sum = 0;
        int j = 0;
        int flag = true;
        for(int i = 0; i < n; i ++) {
            if (j == m) {
                flag = false;
                break;
            }
            if (x[i] <= y[j]) {
                sum += y[j];
                j++;
                continue;
            }
            else {
                j++;
                i--;
                continue;
            }

        }
        if (flag) {
            cout << sum << endl;
        } else {
            cout << "Loowater is doomed!" << endl;
        }

    }

}
