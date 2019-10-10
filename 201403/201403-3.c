#include <stdio.h>
#include <string.h>

int main(void)
{
    int arg[26];
    int argMask[26];
    char argc;
    memset(arg, 0xff, sizeof(int) * 26);
    char str[60];
    char argstr[26][256];
    scanf("%s", str);
    int len = strlen(str);
    int i, j;
    for (i = 0; i < len; i++)
    {
        if (str[i + 1] != ':')
            arg[str[i] - 'a'] = 0; // no argument
        else
        {
            arg[str[i] - 'a'] = 1; // have argument
            i++;
        }
    }

    int count;
    int flag;
    char tempChar;
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        flag = 0;
        memset(argMask, 0, sizeof(int) * 26);
        scanf("%s", str); // ls
        printf("Case %d:", i + 1);
        while (1)
        {
            if (getchar() == '\n')
            {
                flag = 1;
                break;
            }
            scanf("%s", str);
            if (strlen(str) == 2 && str[0] == '-')
            {
                argc = str[1];
                if (arg[argc - 'a'] == -1)
                    break;
                else if (arg[argc - 'a'] == 0)
                    argMask[argc - 'a'] = 1;
                else
                {
                    tempChar = getchar();
                    if (tempChar != '\n')
                    {
                        argMask[argc - 'a'] = 1;
                        scanf("%s", &argstr[argc - 'a'][0]);
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else
                break;
        }
        if (flag == 0)
            while (getchar() != '\n');
        for (j = 0; j < 26; j++)
        {
            if (argMask[j] != 0)
            {
                if (arg[j] == 0)
                    printf(" -%c", j + 'a');
                else
                    printf(" -%c %s", j + 'a', &argstr[j][0]);
            }
        }
        putchar('\n');
    }

    return 0;
}