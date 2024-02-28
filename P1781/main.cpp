#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);
    char* a = new char[100];
    memset(a, 0, sizeof(a));
    int number = 1;
    for (int i = 1; i <= n; i++)
    {
        char* b = new char[100];
        scanf("%s", b);
        if (strlen(a) < strlen(b))
        {
            number = i;
            delete[] a;
            a = b;
        }
        else if (strlen(a) == strlen(b))
        {
            for (int j = 0; j < strlen(a); j++)
                if (a[j] < b[j])
                {
                    number = i;
                    delete[] a;
                    a = b;
                    break;
                }
                else if (a[j] > b[j]) break;
            
        }
    }
    printf("%d\n", number);
    printf("%s", a);
    return 0;
}