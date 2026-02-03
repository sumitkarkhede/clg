//Write a C program to declare primitive and nonprimitive data types and display the
//values of variables, their memory addresses, and their sizes for similar and dissimilar
//data types.

#include <stdio.h>
#include <string.h>
int main()
{
    // Primitive data types
    //premitive data type is a data type provided by the programming language as a basic building block.
    int intVar = 10;
    float floatVar = 5.5;
    char charVar = 'A';
    double doubleVar = 20.99;

    // Non-primitive data types
    //non-premitive data type is a data type that is derived from primitive data types.
    int arrVar[5] = {1, 2, 3, 4, 5};
    struct {
        int id;
        char name[20];
    } structVar = {1, "John"};

    // Print primitive data types
    printf("Primitive Data Types:\n");
    printf("intVar: Value = %d, Address = %p, Size = %zu bytes\n", intVar, (void*)&intVar, sizeof(intVar));
    printf("floatVar: Value = %.2f, Address = %p, Size = %zu bytes\n", floatVar, (void*)&floatVar, sizeof(floatVar));
    printf("charVar: Value = %c, Address = %p, Size = %zu bytes\n", charVar, (void*)&charVar, sizeof(charVar));
    printf("doubleVar: Value = %.2f, Address = %p, Size = %zu bytes\n", doubleVar, (void*)&doubleVar, sizeof(doubleVar));

    // Print non-primitive data types
    printf("\nNon-Primitive Data Types:\n");
    printf("arrVar: Address = %p, Size = %zu bytes\n", (void*)arrVar, sizeof(arrVar));
    for(int i = 0; i < 5; i++) 
    {
        printf("arrVar[%d]: Value = %d, Address = %p\n", i, arrVar[i], (void*)&arrVar[i]);
    }
    printf("structVar: Address = %p, Size = %zu bytes\n", (void*)&structVar, sizeof(structVar));
    printf("structVar.id: Value = %d, Address = %p\n", structVar.id, (void*)&structVar.id);
    printf("structVar.name: Value = %s, Address = %p\n", structVar.name, (void*)&structVar.name);

    return 0;
}