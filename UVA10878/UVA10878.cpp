#include<iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	bool flag = false;
	while (1) {
		getline(cin, input);
		if (input == "___________") {
			if(flag)
				break;
			else
				flag = true;
		} else {
			char n = 0;
			for (int i=0; i < 11; i++) {
				if (input[i] == 'o' || input[i] == ' ') {
					n <<= 1;
					n += (input[i] == 'o');
				}
			}
			cout << n;
		}
	}
	return 0;
}
