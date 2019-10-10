#include <stdio.h>
#include <memory.h>

int main(void) {
    int number;
    int count[10001];
    int numbuf;
    int i;
    int maxnum = 1;
    int maxcount = 0;

    memset(count, 0, sizeof(int) * 10001);

    scanf("%d", &number);

    for(i = 0; i < number; ++i) {
        scanf("%d", &numbuf);
        count[numbuf]++;
    }

    for(i = 1; i <= 10000; ++i) {
        if(count[i] > maxcount) {
            maxcount = count[i];
            maxnum = i;
        }
    }

    printf("%d", maxnum);
    return 0;
}