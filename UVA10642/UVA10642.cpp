#include<iostream>

using namespace std;

int originToPosition(int x, int y);

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int path = originToPosition(x2, y2) - originToPosition(x1, y1);
        
        cout << "Case " << i << ": " << path << endl;
    }
}

int originToPosition(int x, int y) {
    return (((x + y) * (x + y + 1)) / 2) + x;
}
