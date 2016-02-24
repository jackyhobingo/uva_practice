#include<iostream>
#define SIZE 36

using namespace std;

int letter[SIZE];
int ink_used[SIZE+1];

void solve(int number);

int main()
{
	int case_amount;
	cin >> case_amount;

	for(int i = 1; i <= case_amount; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			cin >> letter[j];
		}

		int number_amount;
		cin >> number_amount;
		
		if(i > 1)
			cout << endl;
		cout << "Case " << i << ":" << endl;

		for(int j = 0; j < number_amount; j++)
		{
			int number;
			cin >> number;
			solve(number);
		}
	}
	return 0;
}


void solve(int number)
{
	int min;

	for(int i = 2;i <= SIZE; i++)
	{
		ink_used[i] = 0;
	}
	
	for(int i = 2;i <= SIZE; i++)
	{
		int ink = 0;
		int q = number;
		int r = 0;
		while(q >= i)
		{
			r = q % i;
			q /= i;
			ink += letter[r];
		}
		ink += letter[q];
		ink_used[i] = ink;
		if(min > ink || i == 2)
			min = ink;
	}

	cout << "Cheapest base(s) for number " << number << ":";
	
	for(int i = 2; i<= SIZE;i++)
	{
		if(ink_used[i] == min)
			cout << " " << i;
		cout << endl;
	}

}
