// 5.Write a C program to calculate the physical
// memory address of an element A[i][j] using both Row-Major and Column-Major formulas and verify it against the actual address in memory.

#include <stdio.h>

int main()
{
    int n, m;
    printf("enter rows:");
    scanf("%d", &m);
    printf("enter column:");
    scanf("%d", &n);
    int a[m][n], b;
    // enter matrix elements
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
    // calc for address
    int stop = 0;
    while (1 == 1)
    {

        int p, q;
        printf("enter position of element(p,q):");
        scanf("%d %d", &p, &q);
        int *base_add = &a[0][0];
        printf("Row Major Address Calculation:\n");
        printf("%d ,%d ", base_add + (((p)*n) + (q)), &a[p][q]);
        printf("\nColumn Major Address Calculation:\n");
        printf("%d ,%d ", base_add + (((q)*m) + (p)), &a[p][q]);
        
        // C ALWAYS stores arrays in row-major order
        // Column-major is only a mathematical formula, not real storage.
        printf("\nenter 0 to stop and 1 to continue... ");
        scanf("%d", &stop);
        if (stop == 0)
        {
            break;
        }
    }
    return 0;
}
    /*int x,y;
    printf("enter rows:");
    scanf("%d",&x);
    printf("enter column:");
    scanf("%d",&y);
    int c[x][y];
    printf("enter elemets of matrix: ");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            scanf("%d",&c[j][i]);
        }

    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    //print matrix elements address
    printf("address of elemets:\n");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d : %d\t",c[i][j],&c[j][i]);
        }
        printf("\n");
    }
    //calc for address
    int stop1 = 0;
    while (1)
    {

        int p,q;
        printf("enter position of element(p,q):");
        scanf("%d %d",&p,&q);
        int *base_add=&c[0][0];

        printf("%d ,%d ",base_add + (((p)*y)+(q)),&c[p][q]);
        printf("\nenter 0 to stop and 1 to continue... ");
        scanf("%d",&stop1);
        if (stop1==0)
        {
            break;
        }
    }*/

   