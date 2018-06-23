#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    getchar();
    string input;
    for (int i = 1; i <= cases; i++) {
    int state = 0;
    char concept[2]; 
    string value[2];
    bool assignValue = false;
	getline(cin, input);
	for (int j = 1; j < input.length(); j++) {
             if (assignValue && input[j] != 'W' && input[j] != 'V' && input[j] != 'A') {
                 value[state] += input[j];
             } else if (assignValue) {
                assignValue = false;
                state ++;
             }
             if(input[j] == '=') {
                 concept[state] = input[j - 1];
                 assignValue = true;
             }
        }
        double v[2] = {0.0, 0.0};
        double dot[2] = {0.0, 0.0};
        double dot_digit[2] = {1.0, 1.0};
        double pre[2] = {1.0, 1.0};
        for (int j = 0 ; j< 2; j++){
            bool afterDot = false;
            for(int k=0; k < value[j].length(); k++) {
                if (value[j][k] <= '9' && value[j][k] >= '0') {
                    if(!afterDot)
                        v[j] = v[j]*10 + value[j][k] - '0';
 					else {
                        dot[j] = dot[j] * 10 + value[j][k] - '0';
                        dot_digit[j] /= 10;
				    }
                }
                if (value[j][k] == '.') {
                    afterDot = true;
                } 
                if (value[j][k] == 'm') {
					pre[j] = 0.001;
                }
                if (value[j][k] == 'k') {
					pre[j] = 1000.0;
                }
                if (value[j][k] == 'M') {
					pre[j] = 1000000;
                }
            }
			v[j] = (v[j] + dot[j] * dot_digit[j]) * pre[j];
        }
		cout << fixed << setprecision(2)<< "Problem #" << i << endl;
        if(concept[0] == 'P') {
            if(concept[1] == 'U') {
         		cout << "I="<<v[0] / v[1] << 'A' << endl;       
            } else {
         		cout << "U="<<v[0] / v[1] << 'V' << endl;       
            }
        }
        if(concept[0] == 'U') {
if (concept[1] == 'P') {
         		cout << "I="<<v[1] / v[0] << 'A' << endl;       
            } else {
         		cout << "P=" << v[0] * v[1] << 'W' << endl;       
            }
        }
        if(concept[0] == 'I') { 
            if (concept[1] == 'U') {
         		cout << "P=" << v[0] * v[1] << 'W' << endl;       
				
            } else {
         		cout << "U=" << v[1] / v[0] << 'V' << endl;       
            }
        }
        cout << endl;
    }
}
