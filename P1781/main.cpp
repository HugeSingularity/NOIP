#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);
    char* a = new char[100];
    
    int number = 1;

    scanf("%s", a);
    
    for (int i = 2; i <= n; i++)
    {
        char* b = new char[100];

        scanf("%s", b);
        if (strlen(a) < strlen(b))
        {
            number = i;
            a = b;
        }
        else if (strlen(a) == strlen(b))
        {
            for (int j = 0; j < strlen(b); j++)
                if (a[j] < b[j])
                {
                    number = i;
                    a = b;
                    break;
                }
                else if (a[j] > b[j])
                    break;
        }
    }
    printf("%d\n", number);
    printf("%s", a);
    return 0;
}