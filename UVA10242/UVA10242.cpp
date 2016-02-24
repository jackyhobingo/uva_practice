#include<iostream>
#include<iomanip>

using namespace std;


void findPoint(double ans[], double same[], double a[], double b[])
{
	ans[0] = a[0] - same[0] + b[0];
	ans[1] = a[1] - same[1] + b[1];
}

bool isPosEqual(double pos1[], double pos2[])
{
	return pos1[0] == pos2[0] && pos1[1] == pos2[1];
}


int main()
{
	double pos[4][2];

	while(cin >> pos[0][0] >> pos[0][1] >> pos[1][0] >> pos[1][1] >> pos[2][0] >> pos[2][1] >> pos[3][0] >> pos[3][1])
	{
		double ansPos[2];
		if(isPosEqual(pos[0], pos[2]))
		{
			findPoint(ansPos, pos[0], pos[1], pos[3]);
		}
		else if(isPosEqual(pos[0], pos[3]))
		{
			findPoint(ansPos, pos[0], pos[1], pos[2]);
		}
		else if(isPosEqual(pos[1], pos[2]))
		{
			findPoint(ansPos, pos[1], pos[0], pos[3]);
		}
		else if(isPosEqual(pos[1],pos[3]))
		{
			findPoint(ansPos, pos[1], pos[0], pos[2]);
		}
		cout << setprecision(3) << fixed << ansPos[0] << " " << ansPos[1] << endl;
	}
	return 0;

}


