// 02.write a program for entering elements as row major amd print it

#include <stdio.h>

int main()
{
    int n, m;
    printf("enter rows:");
    scanf("%d", &m);
    printf("enter column:");
    scanf("%d", &n);
    int a[m][n];
    printf("enter elemets of matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[j][i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}