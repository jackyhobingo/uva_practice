#include <stdio.h>
#include <string.h>

int main()
{
    int num, i;
    char buf[10200], tmp[10200];

    while (scanf("%s", tmp) != EOF) {
        buf[0] = '\0';
        strcat(buf, tmp);
        while (buf[strlen(buf) -1] != '#') {
            scanf("%s", tmp);
            strcat(buf, tmp);
        }
        buf[strlen(buf)-1] = '\0';
        num = 0;

        for (i =0; buf[i]!='\0'; i++) {
            num *= 2;
            if (buf[i] == '1')
                num ++;
            while (num >= 131071) {
                num -= 131071;
            }
        }
        if (num) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}
