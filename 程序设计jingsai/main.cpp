#include <cstdio>
#include <cstring>

int main()
{
    char point;
    int p1[5685], p2[5685], p3[2978], p4[2978], cnt1 = 0, cnt2 = 0;
    memset(p1, 0, sizeof(p1));
    memset(p2, 0, sizeof(p2));
    memset(p3, 0, sizeof(p3));
    memset(p4, 0, sizeof(p4));
    for (;;)
    {
        scanf("%c", &point);
        if (point == 'E') break;
        if (point == 'W') p1[cnt1]++, p3[cnt2]++;
        else if(point == 'L') p2[cnt1]++, p4[cnt2]++;
        if (p1[cnt1] >= 11 && p1[cnt1] - p2[cnt1] >= 2 || p2[cnt1] >= 11 && p2[cnt1] - p1[cnt1] >= 2)
        {
            cnt1++;
        }
        if (p3[cnt2] >= 21 && p3[cnt2] - p4[cnt2] >= 2 || p4[cnt2] >= 21 && p4[cnt2] - p3[cnt2] >= 2)
        {
            cnt2++;
        }
    }
    for (int i = 0; i <= cnt1; i++)
    {
        printf("%d:%d\n", p1[i], p2[i]);
    }
    for (int i = 0; i <= cnt2; i++)
    {
        printf("\n%d:%d", p3[i], p4[i]);
    }
    return 0;
}