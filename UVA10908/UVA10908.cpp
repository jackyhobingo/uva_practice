#include<iostream>

using namespace std;


bool isInArea(int m,int n,int M,int N,int len);

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int M, N, Q;
		cin >> M >> N >> Q;
		cout << M << " " << N << " " << Q << endl;
		char array[M][N+1];
		for(int j = 0; j < M; j++)
			cin >> array[j];
		for(int j = 0; j < Q; j++)
		{
			int m, n, r, c, len = 1;
			char x;
			cin >> r >> c;
			x = array[r][c];
			m = r - 1;
			n = c - 1;
			int len_t = len + 2;
			while(isInArea(m, n, M, N, len_t))
			{
				bool isEqual = true;
				for(int k = 0; k < len_t - 1; k++)
				{
					bool a,b,c,d;
					a = array[m + k][n]!= x;
					b = array[m][n + len_t-1 - k]!= x;
					c = array[m + len_t-1][n + k]!= x;
					d = array[m + len_t-1 - k][n + len_t-1]!= x;
					if(a || b || c || d){

						isEqual = false;
						break;
					}

				}
				if(isEqual)
				{
					len = len_t;
					len_t += 2;
					m -= 1;
					n -= 1;
				}
				else
					break;
					

			}
			cout << len << endl;
		}
	}
	return 0;
}

bool isInArea(int m, int n, int M, int N, int len)
{
	if(m < 0 || n < 0)
		return false;
	else if(m + len > M || n + len > N)
		return false;
	else 
		return true;
}
