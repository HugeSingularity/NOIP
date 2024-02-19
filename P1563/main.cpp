#include <cstdio>
#include <cstring>
struct c
{
    bool direction;
    char job[10];
};

struct command
{
    bool a;
    int s;
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    c person[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%hd", &person[i].direction);
        scanf("%s", &person[i].job);
    }
    command b[m];
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%hd%d", &b[i].a, &b[i].s);
        if (person[cnt].direction ^ b[i].a)
        {
            if (cnt + b[i].s >= n)
                cnt = cnt + b[i].s - n;
            else cnt += b[i].s;
        }
        else if (cnt - b[i].s < 0)
            cnt = n - (b[i].s - cnt);
        else cnt -= b[i].s;
    }
    printf("%s", person[cnt].job);
    return 0;
}