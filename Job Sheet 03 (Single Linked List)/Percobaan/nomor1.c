// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Alokasi memori

#include <stdio.h>
#include <stdlib.h>
typedef struct employee_st
{
    char name[40];
    int id;
} Employee;

int main()
{
    int myInt;
    Employee john;
    printf("Size of int is %d\n", sizeof(myInt));
    printf("Size of int is %d\n", sizeof(int));
    printf("Size of Employee is %d\n", sizeof(Employee));
    printf("Size of john is %d\n", sizeof(john));
    printf("Size of char is %d\n", sizeof(char));
    printf("Size of short is %d\n", sizeof(short));
    printf("Size of int is %d\n", sizeof(int));
    printf("Size of long is %d\n", sizeof(long));
    printf("Size of float is %d\n", sizeof(float));
    printf("Size of double is %d\n", sizeof(double));
    return 0;
}
