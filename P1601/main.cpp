#include <cstdio>
#include<cstring>
#include <algorithm>

using namespace std;

struct longData
{
    char data[501];
    int len;

    longData(const char* value = nullptr)
    {
        len = 0;
        memset(data, 0, sizeof(data));
        if (value == nullptr) return;

        auto l = strlen(value);
        for (int i = 0; i < l; i++)
        {
            data[l-1-i] = value[i] - '0';
            len++;
        }
    }

    longData operator+(longData newdata)
    {
        longData plus = longData();
        plus.len = max(len, newdata.len) + 1;
        for (int i = 0; i < plus.len; i++)
        {
            char v = data[i] + newdata.data[i] + plus.data[i];
            plus.data[i] = v % 10;
            plus.data[i + 1] += v / 10;
        }

        for (; plus.len && !plus.data[plus.len - 1];)
        {
            plus.len--;
        }

        return plus;
    }

    void print()
    {
        if (!len) printf("0");
        else
            for (int i = len - 1; i >= 0; i--)
            {
                printf("%d", data[i]);
            }
    }


};


int main()
{
    char data[501];

    scanf("%s", data);
    longData value1 = longData(data);

    scanf("%s", data);
    longData value2 = longData(data);

    auto value3 = value1 + value2;
    
    value3.print();
    return 0;
}