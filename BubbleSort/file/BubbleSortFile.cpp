#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int a[MAX],n;
void Swap(int &a, int &b)
{
	int t=a; a=b; b=t;
}
void Doc(){
	
	FILE *f = fopen("FILE.dat", "r");
    fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++) 
	{	
				fscanf(f, "%d", &a[i]);	
	}
		printf("\nChieu dai mang la: %d",n);
    	printf("\nDanh sach cac phan tu mang:\t");
    for (int i=0; i<n; ++i)
	{
		printf("%d  ",a[i]);
	}
   
    printf("\n");
    fclose(f);
}
void Ghi()
{	
	FILE *fp;
	fp=fopen("KQ.dat","w");
	for(int i=1; i<n;i++)
	{
		fprintf(fp,"%d\n",a[i]);
	}
      fclose(fp); 
}
void BubbleSort(int a[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=n-1;j>i;j--)
			if (a[j]<a[j-1])
				Swap(a[j],a[j-1]);
}
int main()
{
	Doc();
	BubbleSort(a,n);
	Ghi();
}
