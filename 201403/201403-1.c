#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    char num[1001];
    memset(num, 0, 1001);
    int i;
    int tempNum;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        if (tempNum < 0)
            tempNum = -tempNum;
        num[tempNum]++;
    }
    int count = 0;
    for (i = 1; i <= 1000; i++)
    {
        if (num[i] == 2)
            count++;
    }
    printf("%d", count);

    return 0;
}