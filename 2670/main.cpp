#include <cstdio>
int n, m;
char data[100][100];
int walk[8][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1} };

void finding()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (data[i][j] == '*')
            {
                for (int x = 0; x < 8; x++)
                {
                    if (walk[x][0] + i >= 0 && walk[x][0] + i < n && walk[x][1] + j >= 0 && walk[x][1] + j < m)
                    {
                        if (data[i + walk[x][0]][j + walk[x][1]] != '*')
                        {
                            data[i + walk[x][0]][j + walk[x][1]]++;
                        }
                    }
                }
            }
        }
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &data[i][j]);
            if (data[i][j] == '\n' || data[i][j] == ' ') j--;
            if (data[i][j] == '?') data[i][j] = '0';
        }
    finding();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%c", data[i][j]);
        printf("\n");
    }
    return 0;
}