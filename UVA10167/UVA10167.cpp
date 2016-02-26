#include<iostream>

using namespace std;

int main()
{
    int n;
    while(true) {
        cin >> n;
        if(n == 0){
            break;
        }
        int cherry[n*2][2];
        
        for (int i = 0; i < 2 * n; i++) {
            cin >> cherry[i][0] >> cherry[i][1];
        }
        int ans[2];
        bool find = false;
        for (int A = -500; A <= 500; A++) {
            
            for (int B = -500; B <= 500; B++) {
                int num = 0;
                bool cut = false;

                for (int i = 0; i < 2 * n; i ++)
                {
                    if (A*cherry[i][0]+ B*cherry[i][1] < 0) {
                        num += 1;
                    }
                    else if (A*cherry[i][0]+ B*cherry[i][1] > 0) {
                        num -= 1;
                    } 
                    else {
                        cut = true;
                        break;
                    }

                }
                if (num == 0 && !cut) {
                    ans[0] = A;
                    ans[1] = B;
                    find = true;
                    break;
                }   
            }
            if (find) {
                break;
            }
        }
        if (find) {
            cout << ans[0] << " " << ans[1] << endl;
        } 

    }




}
