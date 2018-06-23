#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool finding(int row, int col, int m, int n, string s[50], string search, int l,int drow, int dcol) {
    int rEdge = row + drow * (l - 1);
    int cEdge = col + dcol * (l - 1);    
    if (rEdge >= m || rEdge < 0 || cEdge >= n || cEdge < 0) {
        return false;
    }
    for (int i = 0; i < l; i++) {
        if (s[row][col] != search[i]) {
            return false;
        }
        row += drow;
        col += dcol;
    }
    return true;
}

bool isFound(int row, int col, int m, int n, string s[50], string search) {
    int l = search.length();
    bool ans = false;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j ++) {
            if (! (i==0 && j == 0))
                ans |= finding(row, col, m, n, s, search, l, i, j);
        }
    }
    return ans;
}
int main()
{
    int cases;
    string s[50];
    string search;
    cin >> cases;
    while (cases) {
        int m, n, k;
        cin >> m >> n;        
        for (int i=0; i < m; i++) {
            cin >> s[i];
            transform(s[i].begin(), s[i].end(), s[i].begin(), ::toupper);
        }
        
        cin >> k;
        while(k --) {
            cin >> search;
            transform(search.begin(), search.end(), search.begin(), ::toupper);
            bool ok = false;
            for (int r=0; r < m && !ok; r++) {
       	        for (int c=0; c < n && !ok; c++) {
                    if (isFound(r, c, m, n, s, search)) {
                        cout << r +1 << " "<<  c + 1 << endl;
                        ok = 1;
                    }
                }	
            }
	}
        if (--cases)
            cout << endl;
    }
}
