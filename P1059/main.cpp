#include <cstdio>

short number[1001];

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n--)
    {
        int tmd;
        scanf("%d", &tmd);
        if (!number[tmd])
        {
            m++;
            number[tmd] = tmd;
        }
    }
    printf("%d\n", m);
    for (int i = 1; i <= 1000; i++)
        if (number[i]) printf("%d ", number[i]);
    return 0;
}