#include<iostream>
#include<cstring>
using namespace std;


char s1[31], s2[31];


int binaryToDecimal(char *s)
{
	int num = 0;
	for(int i = 0; i < strlen(s) ; i++)
	{
		num *= 2;
		if(s[i] == '1'){
			num += 1;
		}
	}
	return num;
}
int gcd(int a, int b)
{
	if(a < b)
		return gcd(b, a);
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int main()
{
	int pair;
	cin >> pair;
	for(int i = 1; i <= pair; i++)
	{
		cin >> s1;
		cin >> s2;

		int n1 = binaryToDecimal(s1);
		int n2 = binaryToDecimal(s2);


		cout << "Pair #" << i << ": ";
		if( gcd(n1, n2) == 1)
			cout << "Love is not all you need!" << endl;
		else 
			cout << "All you need is love!" << endl;
	}

}
