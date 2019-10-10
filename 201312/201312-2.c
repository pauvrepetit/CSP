#include <stdio.h>

int main(void) {
    char ISBN[14];
    int realnum;
    int i;

    scanf("%s", ISBN);

    for(i = 0; i < 14; i++) {
        ISBN[i] -= '0';
    }

    realnum = ISBN[0] + ISBN[2] * 2 + ISBN[3] * 3 + ISBN[4] * 4 \
                + ISBN[6] * 5 + ISBN[7] * 6 + ISBN[8] * 7 + ISBN[9] * 8 + ISBN[10] * 9;
    if(realnum % 11 != 10 && realnum % 11 == ISBN[12]) {
        printf("Right");
    } else if(realnum % 11 == 10 && ISBN[12] == 'X' - '0') {
        printf("Right");
    } else {
        for(i = 0; i < 14; i++) {
            ISBN[i] += '0';
        }
        if(realnum % 11 != 10) {
            ISBN[12] = realnum % 11 + '0';
        } else {
            ISBN[12] = 'X';
        }
        ISBN[13] = 0;
        printf("%s", ISBN);
    }

    return 0;
}