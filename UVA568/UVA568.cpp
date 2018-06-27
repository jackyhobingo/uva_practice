#include<cstdio>

int main()
{
	int N;
	int save[10001];
	save[1] = 1;
	int now_max = 1;
	while (scanf(" %d", &N) != EOF) {
		if (N > now_max) {
			for (int i=now_max+1;i<=N;i++){
				save[i] = save[i-1] * i;
				while(save[i] % 10 == 0) {
					save[i] /= 10;
				}
				save[i] %= 100000;
			}
		}
		printf("%5d -> %1d\n", N, save[N] % 10);
	}
	return 0;
}
