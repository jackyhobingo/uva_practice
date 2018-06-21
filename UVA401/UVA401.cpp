#include<iostream>
#include<string>
using namespace std;

char get_mirror(char c)
{
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string mir="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    int i = 0;
    for ( ;c != s[i]; i++) { }
    return mir[i];
}


bool ismirror(string s) {
    int l = s.length();
    int lower = l / 2;
    int upper = l / 2;
    if( l % 2 == 0) {
        // even
        lower -= 1;
    }
    while (lower >= 0) {
        if(s[lower] == get_mirror(s[upper])) {
            lower -= 1;
            upper += 1;
        } else {
            return false;
        }
    } 
    return true;
}
bool ispalindrome(string s) {
    int l = s.length();
    int lower = l / 2;
    int upper = l / 2;
    if (l % 2 == 0) {
        lower -= 1;
    }
    while (lower >= 0) {
        if(s[lower] == s[upper]) {
            lower -= 1;
            upper += 1;
        } else {
            return false;
        }
    } 
    return true;
}

int main()
{
    string s;
    while (cin >> s)
    {
        bool mirror = ismirror(s);
        bool palindrome = ispalindrome(s);
        cout << s << " -- is";
        if (mirror && palindrome) {
            cout << " a mirrored palindrome." << endl;
        } else if (mirror) {
            cout << " a mirrored string." << endl;
        } else if (palindrome) {
            cout << " a regular palindrome." << endl;
        } else {
            cout << " not a palindrome." << endl;
        }
        cout << endl;
    }
}
