#include <cstdio>
#include <cstring>
struct c
{
    bool direction;
    char job[11];
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
            cnt = (cnt + b[i].s) % n;
        }
        else cnt = (cnt - b[i].s + n) % n;
    }
    printf("%s", person[cnt].job);
    return 0;
}