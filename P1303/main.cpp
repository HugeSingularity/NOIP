#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct add
{
    char a[4010];
    int len = 0;

    add(char x[] = nullptr)
    {
        memset(a, 0, sizeof(a));
        if (x == nullptr) return;
        int l = strlen(x);
        for (int i = 0; i < l; i++)
        {
            a[l - 1 - i] = x[i] - '0';
            len++;
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
        add tmp;
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
        add tmp;
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
    char x[2010], y[2010];
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    scanf("%s%s", x, y);
    add a(x);
    add b(y);
    add c = a * b;
    if (c.len == 0)
    {
        printf("0");
        return 0;
    }
    for (int i = c.len - 1; i >= 0; i--)
        printf("%d", c.a[i]);
    return 0;
}