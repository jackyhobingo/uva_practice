#include<iostream>
using namespace std;
int main()
{
    int n;
    int game = 0;
    int ans[1000];
    int a[1000];
    bool ans_[1000];
    bool a_[1000];
    int tmp;
    while(1) {
        game ++;
        cin >> n;
        if(n == 0){
             break;
		}
        cout << "Game " << game << ":" << endl;
		for(int i=0; i< n ; i++) {
			cin >> ans[i];
		}
        while (1) {
    		int t = 0, f=0;
            bool b = 1;
			for(int i=0; i< n ; i++) {
				cin >> a[i];
                ans_[i] = false;
                a_[i] = false;
                if (ans[i] == a[i]) {
                    t ++;
                    ans_[i] = true;
                    a_[i] = true;
                }
			}
            for(int i=0; i<n; i++) {
                if (a[i]==0) {
					b= false;
				}
            }
            if (!b) {
               break;
            }
			for (int i=0; i < n; i++) {
                if(a_[i]) {
					continue;
				}
	 			for (int j=0; j < n; j++) {
                    if(ans_[j]) {
						continue;
					}
					if (a[i] == ans[j] && i != j) {
						f ++;
						a_[i] = true;
                        ans_[j] = true;
                        break;
					} 
				}
			}
            cout << "    (" << t << ","<< f << ")" << endl; 
        }
    }
}
