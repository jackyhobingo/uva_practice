#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    char s[1000001];
    
    int len;
    bool flag;
    int i, j, k;
    while (scanf("%s", s) != EOF) {
        if (s[0] == '.') {
            break;
        }
        len = strlen(s);
        for (i = 1; i <= len; i++) {
            if (len % i != 0) {
                continue;
            }
            flag = true;
            for (j = i; j < len && flag; j += i) {
                for (k = 0; k < i; k++) {
                    if (s[k] != s[j+k]) {
                        flag = false;
                        break;
                    }
                }
            }
           
            if (flag) {
                printf("%d\n", len/i);
                break;
            }
        }
    }

    return 0;
}

