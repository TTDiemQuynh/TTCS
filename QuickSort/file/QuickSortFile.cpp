#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
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
void Swap(int &a, int &b)
{
	int t=a; a=b; b=t;
}
void QuickSort(int a[], int l, int r)
{	int i=l; int j=r; int mid= a[(l+r)/2];
	do
	{
		while(a[i]<mid)
			i++;
		while (mid<a[j])
			j--;
		if(i<=j)
		{
			Swap(a[i],a[j]);
			i++; j--;
		} 
		} while (i<=j);
		if(i<r)
			QuickSort(a,i,r);
		if(l<j)
			QuickSort(a,l,j);
	
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

int main()
{
	Doc();
	QuickSort(a,0,n-1);
	Ghi();
}
