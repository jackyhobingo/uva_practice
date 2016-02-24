#include<iostream>

using namespace std;

int gcd(int, int);

int main()
{
	int N;
	while(true)
	{
		cin >> N;
		
		if(N == 0)
			break;

		int sum = 0;
		for(int i = 1; i < N; i++)
		{
			for(int j = i + 1; j <= N; j++)
			{
				sum += gcd(j, i);
			}
		}
		cout << sum << endl;
	}

	return 0;
}


int gcd(int a, int b)
{
	if(a < b)
		return gcd(b, a);
	else if(b == 0)
		return a;
	else
		return gcd(b,  a % b);
}
