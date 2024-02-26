#include <cstdio>

struct student
{
    int a, b, c, together, number = 0;
    student(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c), together(a + b + c){}
    student operator= (student x)
    {
        a = x.a;
        b = x.b;
        c = x.c;
        together = x.together;
        number = x.number;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    student m[n];
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        m[i] = student(a, b, c);
        m[i].number = i + 1;
    }
    for (int i = 0; i < 5; i++)
        for (int j = i; j < n; j++)
        {
            if (m[j].together < m[j + 1].together || m[j].together == m[j + 1].together && (m[j].a < m[j + 1].a || m[j].a == m[j + 1].a && m[j].number > m[j + 1].number))
            {
                student tmp = m[j];
                m[j + 1] = m[j];
                m[j] = tmp;
            }
        }
    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\n", m[i].number, m[i].together);
    }
    return 0;
}