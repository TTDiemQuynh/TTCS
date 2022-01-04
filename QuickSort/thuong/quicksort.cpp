#include<stdio.h>
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
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
    quickSort(arr, 0, n-1);
    printf("\n Day sau khi sap xep: \n");
    printArray(arr, n);
    return 0;
}
