#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    int window[10][5];
    int localex, localey;
    int tempx0, tempy0, tempx1, tempy1, tempi;
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &window[i][0], &window[i][1], &window[i][2], &window[i][3]);
        window[i][4] = i;
    }
    for (j = 0; j < m; j++)
    {
        scanf("%d%d", &localex, &localey);
        for (i = n - 1; i >= 0; i--)
        {
            if (localex >= window[i][0] && localex <= window[i][2] && localey >= window[i][1] && localey <= window[i][3])
            {
                printf("%d\n", window[i][4] + 1);
                tempx0 = window[i][0];
                tempy0 = window[i][1];
                tempx1 = window[i][2];
                tempy1 = window[i][3];
                tempi = window[i][4];
                for (k = i; k < n - 1; k++)
                {
                    window[k][0] = window[k + 1][0];
                    window[k][1] = window[k + 1][1];
                    window[k][2] = window[k + 1][2];
                    window[k][3] = window[k + 1][3];
                    window[k][4] = window[k + 1][4];
                }
                window[k][0] = tempx0;
                window[k][1] = tempy0;
                window[k][2] = tempx1;
                window[k][3] = tempy1;
                window[k][4] = tempi;
                break;
            }
        }
        if (i < 0)
            printf("IGNORED\n");
    }
    return 0;
}