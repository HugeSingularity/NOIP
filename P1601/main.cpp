#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct add
{
    char a[502];
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

    add operator+ (add b)
    {
        add tmp;
        tmp.len = max(len, b.len) + 1;
        for (int i = 0; i < tmp.len - 1; i++)
        {
            char v = a[i] + b.a[i] + tmp.a[i];
            tmp.a[i] = v % 10;
            tmp.a[i + 1] += v / 10;
        }
        for (; tmp.len && !tmp.a[tmp.len - 1];)
            tmp.len--;
        return tmp;
    }
};

int main()
{
    char x[502], y[502];
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    scanf("%s%s", x, y);
    add a(x);
    add b(y);
    add c = a + b;
    if (c.len == 0)
    {
        printf("0");
        return 0;
    }
    for (int i = c.len - 1; i >= 0; i--)
        printf("%d", c.a[i]);
    return 0;
}