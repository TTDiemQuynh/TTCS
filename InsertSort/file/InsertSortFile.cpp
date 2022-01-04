#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int a[MAX],n;
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

void InsertSort(int a[], int n)
{
	for (int i=1;i<n;i++)
	{
		int tam=a[i],j=i-1;
		for (;j>=0;j--)
			if (tam<a[j])
				a[j+1]=a[j];
			else break;
		a[j+1]=tam;
	}
}

int main()
{
	Doc();
	InsertSort(a,n);
	Ghi();
}
