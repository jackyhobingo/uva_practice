#include<iostream>

using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    while (N--) {
        int size;
        cin >> size;
        int train[size];
        for (int i = 0; i < size; i++) {
            cin >> train[i];
        }

        int count;
        count = 0;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (train[j] > train[j+1]){
                    swap(train[j], train[j+1]);
                    count++;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps." << endl;
    }

    return 0;
}
