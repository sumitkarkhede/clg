// 01.write a program for entering elements as row major amd print it

#include <stdio.h>

int main()
{
    int n, m;
    printf("enter rows:");
    scanf("%d", &m);
    printf("enter column:");
    scanf("%d", &n);
    int a[m][n];
    // enter matrix elements
    printf("enter elemets of matrix: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // print matrix elements
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