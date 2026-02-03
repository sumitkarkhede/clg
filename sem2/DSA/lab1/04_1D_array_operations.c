// 4.  Write a program to store N integers in a 1D array. The program should:
// 5.​Find the maximum and minimum elements.
// ​6.Calculate the average of all elements.
// 7.Perform a Linear Search for a specific key entered by the user

#include <stdio.h>

int main()
{
    int n, i, search, found = 0, max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // linear search
    printf("Enter the element to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            printf("Element found at position %d (index %d)\n", i + 1, i);
            found = 1;
            break; // stop after finding the element
        }
    }

    if (found == 0)
    {
        printf("Element not found in the array.\n");
    }

    // max min
    max = arr[0];
    min = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] > max)
        {
            max = arr[i + 1];
        }
        if (arr[i + 1] < min)
        {
            min = arr[i + 1];
        }
    }

    printf("max=%d min=%d", max, min);

    // average
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    float average = sum / (float)n;
    printf("\naverage=%.2f", average);

    return 0;
}
