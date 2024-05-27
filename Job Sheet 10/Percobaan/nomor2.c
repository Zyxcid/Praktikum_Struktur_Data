#include <stdio.h>

int main()
{
    int L[20], temp, i, j, n = 6, m;
    printf("pengurutan berdasarkan Shell sort \nmasukkan %d elements : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &L[i]);
    }
    printf("\nsebelum sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", L[i]);
    }
    for (m = n / 2; m > 0; m /= 2)
    {
        for (j = m; j < n; j++)
        {
            for (i = j - m; i >= 0; i -= m)
            {
                if (L[i + m] >= L[i])
                {
                    break;
                }
                else
                {
                    temp = L[i];
                    L[i] = L[i + m];
                    L[i + m] = temp;
                }
            }
        }
    }
    printf("\nsetelah sorting : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", L[i]);
    }
    printf("\n");
}