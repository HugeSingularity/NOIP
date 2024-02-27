#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);
    char a[100];
    memset(a, 0, sizeof(a));
    int number = 1;
    for (int i = 1; i < n; i++)
    {
        char b[100];
        scanf("%s", b);
        if (strlen(a) < strlen(b))
        {
            number = i;
            for (int j = 0; j < strlen(b); j++)
                a[j] = b[j];
        }
        else if (strlen(a) == strlen(b))
        {
            for (int j = 0; j < strlen(a); j++)
                if (a[j] < b[j])
                {   number = i;
                    for (int m = 0; m < strlen(b); m++)
                        a[m] = b[m];
                }
        }
    }
    printf("%d\n", number);
    for (int i = 0; i < strlen(a); i++)
        printf("%d", a[i]);
    return 0;
}