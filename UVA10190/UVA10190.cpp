#include<iostream>

using namespace std;

int main()
{
	int n1, n2;
	
	while(cin >> n1 >> n2)
	{
		bool isBoring;	
		int t = n1;
	
		while(true)
		{
			if(n1 < 2 || n2  < 2 || t % n2 != 0)
			{
				isBoring = true;
				break;
			}
			else if(t / n2 != 1 && t > 1){
				t /= n2;
			} else {
				isBoring = false;
				break;
			}
		}

		if(isBoring)
		{
			cout << "Boring!" << endl;
		}
		else
		{
			while(n1 != 1)
			{
				cout << n1 << " ";
				n1 /= n2;
			}
			cout << "1" << endl;
		}
	}

	return 0;
}
