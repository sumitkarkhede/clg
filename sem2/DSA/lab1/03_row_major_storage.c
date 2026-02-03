// 3.Given a 3 x3 matrix, print the elements and
// their memory addresses. Demonstrate that in C,
// the address of A[0][1] follows immediately after A[0][0],
// proving Row-Major storage. Provide me the solution

#include <stdio.h>

int main()
{
    int n, m;
    printf("enter rows:");
    scanf("%d", &m);
    printf("enter column:");
    scanf("%d", &n);
    int a[m][n];
    // enetr matrix elements
    printf("enter elemets of matrix: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // print matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    // print matrix elements address
    printf("address of elemets:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d : %d\t", a[i][j], &a[i][j]);
        }
        printf("\n");
    }
    printf("address of a[0][0] is %d and address of a[0][1] is %d which is just next address location", &a[0][0], &a[0][1]);
    return 0;
}