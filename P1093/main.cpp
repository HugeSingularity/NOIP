#include <cstdio>

struct student
{
    int a, b, c, together, number = 0;
    student(int a = 0, int b = 0, int c = 0, int number = 1) : a(a), b(b), c(c), together(a + b + c), number(number){}
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
        m[i] = student(a, b, c, i + 1);
    }
    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (m[i].together < m[j].together || m[i].together == m[j].together && (m[i].a < m[j].a || m[i].a == m[j].a && m[i].number > m[j].number))
            {
                student tmp = m[i];
                m[i] = m[j];
                m[j] = tmp;
            }
        }
    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\n", m[i].number, m[i].together);
    }
    return 0;
}