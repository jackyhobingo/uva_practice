#include<iostream>
#include<cstring>

using namespace std;

char s1[31], s2[31];

int gcd(int, int);
int binaryToDecimal(char *);

int main()
{
	int pair;
	cin >> pair;
	for(int i = 1; i <= pair; i++)
	{
		cin >> s1 >> s2;
		
		int n1 = binaryToDecimal(s1);
		int n2 = binaryToDecimal(s2);

		cout << "Pair #" << i << ": ";
		if( gcd(n1, n2) == 1)
			cout << "Love is not all you need!" << endl;
		else 
			cout << "All you need is love!" << endl;
	}

}

int gcd(int a, int b)
{
	if(a < b)
		return gcd(b, a);
	else if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int binaryToDecimal(char *s)
{
	int num = 0;
	
	for(int i = 0; i < strlen(s) ; i++)
	{
		num *= 2;
		if(s[i] == '1')
			num += 1;
	}
	return num;
}

