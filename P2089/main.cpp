#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int resolve(unsigned int& v, char* d)
{
    int x = 0, y = v;
    for (int i = 0; i < 10; i++)
    {
        y = v >> (i * 2);
        char a = y % 4;
        if (!a)
        {
            a = 1;
            v += 1 << (i * 2);
        }
        d[i] = a;
        x += a;
    }

    return x;
}

int main()
{
    int n = 0;
    char data[10];
    vector<char*> results;

    scanf("%d", &n);

    if (n < 10 || n > 30)
    {
        printf("%d", 0);
        return 0;
    }

    unsigned int p = 0;

    for (int i = 0; i < 10; i++)
    {
        p += 1 << (i * 2);
        data[i] = 1;
    }

    int m = 10;
    int ans = 0;

    do
    {
        m = resolve(p, data);

        if (m == n)
        {
            ans++;
            char* result = new char[100] {};
            char buffer[10];
            for (int i = 9; i >= 0; i--)
            {
                sprintf(buffer, "%d ", data[i]);
                strcat(result, buffer);
                
            }

            results.push_back(result);
        }

        p++;
    } while (p >> 20 == 0);

    printf("%d\n", ans);
    for (auto i : results)
    {
        printf("%s\n", i);
    }

    return 0;
}