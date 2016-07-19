#include<iostream>

using namespace std;

int main()
{
    double input;
    double sum;
    while(cin >> input) {
        if(input == 0.00) {

            break;
        }
        sum = 0;
        int count = 0;
        for (double i = 2.0; sum < input; i+=1.0) {
            sum += (1.00/ i);
            count ++;
            if(sum >= input) {
                cout << count << " card(s)" << endl;
                break;
            }
        }

    }    
    return 0;
}
