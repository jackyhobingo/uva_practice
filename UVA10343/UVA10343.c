#include <stdlib.h>
#include <stdio.h>

int main()
{
    
    char c;
    char base64[66] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    char in = '#', pre='0';
    char input[4];
    int indexToBinary = 0;
    int charnumber = 0;
    int i,j;
    while (scanf("%c", &in)!=1) {

        for (j = 0; j < 66; j++){
            if (in == base64[j]) 
                break;
        }
        if (j < 65) {
            input[charnumber] = in;
            pre = in;
            charnumber++;
        }
        else if (in == '#') {
            if (pre != '#') {
                printf("#");
                pre = '#';
            } 
        }
        if (charnumber == 4) {
            for (i = 0; i < 4; i++) {
                if (input[i] == '=') {
                    indexToBinary *= 64;
                } 
                else {
                    for (j = 0; j < 66; j++) {
                        if(input[i] == base64[j]) 
                            break;
                    }
                    indexToBinary = ((indexToBinary * 64) + j);
                }
            }
            printf("%c",indexToBinary / 256/ 256) ;
            if (input[2] != '=') {
                printf("%c",(indexToBinary / 256));
            }
            if (input[3] != '=') {
                printf("%c", indexToBinary);
            }
            charnumber = 0;
            indexToBinary = 0;
        }
    }
    return 0;
}

