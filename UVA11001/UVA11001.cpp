#include <iostream>

using namespace std;

int main()
{
    
    int Vt, V0;

    while (cin >> Vt >> V0) {
     
        if (Vt == 0 && V0 == 0) {
            break;
        }  
        int r = Vt %  (2 * V0);
        if (r == V0) {
            cout << 0 << endl;
        }
        else if (r < V0) {
            cout << Vt / (2 * V0) << endl;
        }
        else {
            cout << Vt / (2 * V0) + 1 << endl;
        } 


    }


}
