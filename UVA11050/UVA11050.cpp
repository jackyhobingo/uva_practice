#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int range, P;
		cin >> range >> P;
		
		int day[range + 1];

		for(int j = 0; j <= range;j++)
			day[j] = 0;

		for(int j = 0; j < P; j++)
		{
			int T;
			cin >> T;
			int now = T;
			while(range + 1 > now)
			{
				day[now] = 1;
				now += T;
			}
		}
		int sum = 0;
		for(int j = 1; j <= range; j++)
		{
			if(day[j] == 1 && (j % 7 != 0 && j % 7 != 6))
				sum += 1;
		}
		cout << sum << endl;
	}
}
