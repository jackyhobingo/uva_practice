#include<stdio.h>
int main()
{
    int i, n, t;
    int ans[101] = {};
    while(scanf("%d", &n)){
        if(n==0){
            break;
        }

        for (i = 0 ; i < n; i++){
            scanf("%d", &t);
            ans[t] += 1;
        }
        
        int start = 1;
        for (i = 1; i < 101 ; i++){
            while(ans[i]) {
                if (!start) {
                    printf(" ");
                }
                printf("%d", i);
                start = 0;
                ans[i]--;
            }       
        }
        printf("\n");
    }
    return 0;
}
