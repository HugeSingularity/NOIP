#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct add
{
    int a[4010];
    int len = 0;

    add(int x = 0)
    {
        memset(a, 0, sizeof(a));
        while (x)
        {
            a[len++] = x % 10;
            x /= 10;
        }
    }

    void carry()
    {
        for (int i = 0; i < len; i++)
        {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        for (; len && !a[len - 1];)
            len--;
    }

    add operator* (add b)
    {
        add tmp(0);
        tmp.len = len + b.len;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < b.len; j++)
            {
                int l = i + j;
                tmp.a[l] += a[i] * b.a[j];
            }
        }
        tmp.carry();
        return tmp;
    }

    add operator+ (add b)
    {
        add tmp(0);
        tmp.len = max(len, b.len) + 1;
        for (int i = 0; i < tmp.len - 1; i++)
        {
            tmp.a[i] = a[i] + b.a[i];
        }
        tmp.carry();
        return tmp;
    }
};

int main()
{
    short n;
    add ans;
    scanf("%hd", &n);
    add b[n + 1];
    b[1] = add(1);
    ans = b[1];
    for (int i = 2; i <= n; i++)
    {
        b[i] = add(i) * b[i - 1];
        ans = ans + b[i];
    }
    for (int i = ans.len - 1; i >= 0; i--)
        printf("%d", ans.a[i]);
}