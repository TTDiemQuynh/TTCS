#include <stdio.h>
#include <math.h>
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
int main()
{
    int i, number;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &number);
    int arr[number];
    printf("Nhap cac phan tu cua mang: \n");
    for (i = 0; i < number; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Cac phan tu cua mang: \n");
    for (i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printf("\nDay sau khi duoc sap xep: \n");
    printArray(arr, n);
    return 0;
}
