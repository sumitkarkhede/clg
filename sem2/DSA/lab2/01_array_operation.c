//1: Array Operations in C

/*Tasks:
1. Array Creation: 
    Create three signed integer arrays:
    o SubArray1, SubArray2 of size 10.
    o MainArray of size 20.
2. Operations:
    Implement a menu to perform the following operations on the arrays and
    print the array elements after each operation:
x   o Insert elements at the end, beginning, and user-given position.
    o Delete elements from the end, beginning, and user-given position.
    o Reverse the array using:
        ▪ A temporary array to hold the result.
        ▪ In-place reversal (without a temporary array).
    o Copy a sequence of elements from the subarray (SubArray1 or SubArray2) to
    MainArray.
    o Merge two sorted arrays in descending order.
    o Display the sum of all array elements:
        ▪ Without recursion.
        ▪ Using recursion.
    o Search the array for a user-given value.
    o Separate the MainArray into sub-arrays for:
        ▪ Odd and even numbers.
        ▪ Positive and negative numbers.*/

       
#include <stdio.h>
#include <stdlib.h>
int SubArray1[10], SubArray2[10], MainArray[20];
int n1 = 0, n2 = 0, nMain = 0;

void getarray(int arr[], int *n, int k);
void menu();
void insertAtEnd();
void insertAtBeginning();
void insertAtPosition();
void deleteFromEnd();
void deleteFromBeginning();
void deleteFromPosition();
void reverseWithTemp();
void reverseInPlace();
void copy();
void merge();
void sumWithoutRecursion();
int sumWithRecursion();
void search();
void separateMainArray();

void getarray(int arr[], int *n, int k)
{
    printf("Enter number of elements in SubArray%d: ", k);
    scanf("%d", n);

    if (*n > 10) {
        printf("Max size is 10\n");
        *n = 10;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void menu()
{
    printf("\n\n____________________________________\n");
    printf("\nMenu:\n");
    printf("1. Insert elements at the end\n");
    printf("2. Insert elements at the beginning\n");
    printf("3. Insert elements at a user-given position\n");
    printf("4. Delete elements from the end\n");
    printf("5. Delete elements from the beginning\n");
    printf("6. Delete elements from a user-given position\n");
    printf("7. Reverse array using temporary array\n");
    printf("8. Reverse array in-place\n");
    printf("9. Copy elements to MainArray\n");
    printf("10. Merge two sorted arrays in descending order\n");
    printf("11. Display sum of array elements without recursion\n");
    printf("12. Display sum of array elements with recursion\n");
    printf("13. Search for a value\n");
    printf("14. Separate MainArray into sub-arrays\n");
    printf("enter 0 to exit\n\n");
    printf("____________________________________\n\n");

    printf("enter choicce:\n");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {   
        case 1:
             insertAtEnd();
            break;
        case 2:
             insertAtBeginning();
            break;
        case 3:
             insertAtPosition();
            break;
        case 4:
             deleteFromEnd();
            break;
        case 5:
             deleteFromBeginning();                               
            break;
        case 6:
             deleteFromPosition();
            break;  
        case 7:
             reverseWithTemp();
            break;
        case 8:
             reverseInPlace();
            break;
        case 9:
             copy();
            break;
        case 10:
             merge();
            break;
        case 11:
             sumWithoutRecursion();
            break;
        case 12:
             sumWithRecursion();
             
             break;
        case 13:
             search();
            break;
        case 14:
             separateMainArray();
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}
void insertAtBeginning()
{
    printf("Inserting element into SubArray1 at the beginning\n");
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = n1; i > 0; i--) {
        SubArray1[i] = SubArray1[i - 1];
    }   
    SubArray1[0] = val;
    n1++;
    printf("Element inserted. New array:\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("%d ", SubArray1[i]);
    }
}
void insertAtEnd()
{
    printf("Inserting element into SubArray1 at the end\n");
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    SubArray1[n1] = val;
    n1++;
    printf("Element inserted. New array:\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("%d ", SubArray1[i]);
    }
}
void insertAtPosition()
{
    printf("Inserting element into SubArray1\n");
    int pos,val;
    printf("Enter position to insert element (0 to %d): ", n1);
    scanf("%d", &pos);
    if (pos < 0 || pos > n1) {
        printf("Invalid position\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = n1; i > pos; i--) {
        SubArray1[i] = SubArray1[i - 1];
    }   
    SubArray1[pos] = val;
    n1++;
    printf("Element inserted. New array:\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("%d ", SubArray1[i]);
    }
}
void deleteFromEnd()
{
    if (n1 == 0) {
        printf("Array is empty, cannot delete\n");
        return;
    }
    n1--;
    printf("Element deleted from end. New array:\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("%d ", SubArray1[i]);
    }
}
void deleteFromBeginning()
{
    if (n1 == 0) {
        printf("Array is empty, cannot delete\n");
        return;
    }
    for (int i = 0; i < n1 - 1; i++) {
        SubArray1[i] = SubArray1[i + 1];
    }
    n1--;
    printf("Element deleted from beginning. New array:\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("%d ", SubArray1[i]);
    }
}
void deleteFromPosition()
{
    int pos;
    printf("Enter position to delete element (0 to %d): ", n1 - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n1) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < n1 - 1; i++) {
        SubArray1[i] = SubArray1[i + 1];
    }
    n1--;
    printf("Element deleted from position %d. New array:\n", pos);
    for (int i = 0; i < n1; i++) 
    {
        printf("%d ", SubArray1[i]);
    }
}
void reverseWithTemp()
{
    int temp[10];
    for (int i = 0; i < n1; i++) {
        temp[i] = SubArray1[n1 - 1 - i];
    }
    for (int i = 0; i < n1; i++) {
        SubArray1[i] = temp[i];
    }
    printf("Array reversed using temporary array. New array:\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("%d ", SubArray1[i]);
    }
}
void reverseInPlace()
{
    int start = 0;
    int end = n1 - 1;
    while (start < end) {
        int temp = SubArray1[start];
        SubArray1[start] = SubArray1[end];
        SubArray1[end] = temp;
        start++;
        end--;
    }
    printf("Array reversed in-place. New array:\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("%d ", SubArray1[i]);
    }
}
void copy()
{
    printf("Copying elements from SubArray1 to MainArray\n");
    for (int i = 0; i < n1; i++) {
        MainArray[i] = SubArray1[i];
    }
    nMain = n1;
    printf("Elements copied. MainArray:\n");
    for (int i = 0; i < nMain; i++) 
    {
        printf("%d ", MainArray[i]);
    }
}
void merge()
{
    printf("Merging SubArray1 and SubArray2 into MainArray in descending order\n");
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (SubArray1[i] > SubArray2[j]) {
            MainArray[k++] = SubArray1[i++];
        } else {
            MainArray[k++] = SubArray2[j++];
        }
    }
    while (i < n1) {
        MainArray[k++] = SubArray1[i++];
    }
    while (j < n2) {
        MainArray[k++] = SubArray2[j++];
    }
    nMain = k;
    printf("Arrays merged. MainArray:\n");
    for (int i = 0; i < nMain; i++) 
    {
        printf("%d ", MainArray[i]);
    }
}

void sumWithoutRecursion()
{
    int total = 0;
    for (int i = 0; i < n1; i++) {
        total += SubArray1[i];
    }
    printf("Sum of elements in SubArray1 without recursion: %d\n", total);
}

int sumWithRecursionHelper(int arr[], int n)
{
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + sumWithRecursionHelper(arr, n - 1);
}

int sumWithRecursion()
{
    int total = sumWithRecursionHelper(SubArray1, n1);
    printf("Sum of elements in SubArray1 with recursion: %d\n", total);
    return total;
}


void search()
{
    int val, found = 0;
    printf("Enter value to search in SubArray1: ");
    scanf("%d", &val);
    for (int i = 0; i < n1; i++) {
        if (SubArray1[i] == val) {
            printf("Value %d found at index %d\n", val, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d not found in SubArray1\n", val);
    }
}   

void separateMainArray()
{
    if (nMain == 0) {
        printf("MainArray is empty. Please copy or merge first.\n");
        return;
    }

    int even[20], odd[20], pos[20], neg[20];
    int e = 0, o = 0, p = 0, n = 0;

    for (int i = 0; i < nMain; i++) {
        if (MainArray[i] % 2 == 0)
            even[e++] = MainArray[i];
        else
            odd[o++] = MainArray[i];

        if (MainArray[i] >= 0)
            pos[p++] = MainArray[i];
        else
            neg[n++] = MainArray[i];
    }

    printf("Even: ");
    for (int i = 0; i < e; i++)
        printf("%d ", even[i]);

    printf("\nOdd: ");
    for (int i = 0; i < o; i++)
        printf("%d ", odd[i]);

    printf("\nPositive: ");
    for (int i = 0; i < p; i++)
        printf("%d ", pos[i]);

    printf("\nNegative: ");
    for (int i = 0; i < n; i++)
        printf("%d ", neg[i]);

    printf("\n");
}




int main() 
{
    int k=1;
    getarray(SubArray1, &n1,k);
    k++;
    getarray(SubArray2, &n2,k);
    while(1)
    {
        menu();
    }  
    return 0;
}
