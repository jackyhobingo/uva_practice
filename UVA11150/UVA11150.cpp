#include<iostream>

using namespace std;

int main()
{
    int New, notChange;
    while(cin >> notChange){
        int sum = notChange;
        while(notChange > 2) {
            New = notChange / 3;
            notChange = notChange % 3 + New;
        
            sum += New;
        }
        if(notChange == 2)
        sum += 1;
        cout << sum << endl;
    }

}
