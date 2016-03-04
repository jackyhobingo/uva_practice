#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    map<string, int> hay;
    string s;
    while (m--) {
        int money;
        cin >> s >> money;
        hay[s] = money; 
    }
    while (n--) {
        int ans = 0;
        while (cin >> s && s != ".") {
            ans += hay[s];
        }
        cout << ans << endl;
    }

}
