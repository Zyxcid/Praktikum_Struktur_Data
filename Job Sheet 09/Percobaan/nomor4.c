#include <stdbool.h>
#include <stdio.h>
#define MAX 7

int intArray[MAX] = {4, 6, 3, 2, 1, 9, 7};

void printline(int count)
{
    int i;
    for (i = 0; i < count - 1; i++)
    {
        printf("=");
    }
    printf("=\n");
}

void display()
{
    int i;
    printf("[");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", intArray[i]);
    }
    printf("]\n");
}

void selectionSort()
{
    int indexMin, i, j;

    for (i = 0; i < MAX - 1; i++)
    {
        indexMin = i;

        for (j = i + 1; j < MAX; j++)
        {
            if (intArray[j] < intArray[indexMin])
            {
                indexMin = j;
            }
        }
        if (indexMin != i)
        {
            printf("Angka yang ditukar: [ %d, %d ]\n", intArray[i], intArray[indexMin]);
            // Tukar angka
            int temp = intArray[indexMin];
            intArray[indexMin] = intArray[i];
            intArray[i] = temp;
        }
        printf(" -- Iterasi %d#: ", (i + 1));
        display();
    }
}

int main()
{
    printf("Array Input: ");
    display();
    printline(50);
    selectionSort();
    printline(50);
    printf("Array Output: ");
    display();
}