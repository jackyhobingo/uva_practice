#include <iostream>
#include <string>
#include <map>




using namespace std;
map<string, int> tree;
map<string, int>::iterator it;
string line, name;
char str[100];
int main()
{
    int n;
    int i = 0;
    cin >> n;
    
    getline(cin, line);
    getline(cin, line);
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        tree.clear();
        while(getline(cin, name)){

            if (name[0] == '\0') {
                break;
            }
            
            count ++;
            it = tree.find(name);
            if (it == tree.end()) {
                tree[name] = 1;
            }
            else {
                tree[name]++;
            }
        }
        if (i > 0) {
            cout << endl;
        } 
        for (it = tree.begin(); it != tree.end(); it++) {
            float per = 100.0 * it->second / count;
            cout.precision(4);
            cout.setf(cout.fixed);
            cout << it->first << " " << per << endl;
        }

    }
    return 0;
}
