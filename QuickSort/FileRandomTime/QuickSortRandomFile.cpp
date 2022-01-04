#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
void RanDom(int a[], int n, int b, int c)//b<=c
{
	srand((int)time(0));
	for (int i=0;i<n;i++)
		a[i]=b+rand()%(c-b+1);
}


void Ghi(int a[], int n)
{	
	FILE *fp;
	fp=fopen("E:\\TRUONGTHIDIEMQUYNH_61136433_DE04\\SAP XEP\\QuickSort\\FileRandomTime\\FILE.dat","w");
	fprintf(fp,"%d\n",n);
	for(int i=0; i<n;i++)
	{
		fprintf(fp,"%d\t",a[i]);
	}
		 
	
      fclose(fp); 
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
	

void Doc(int a[], int n){
	
	FILE *f = fopen("E:\\TRUONGTHIDIEMQUYNH_61136433_DE04\\SAP XEP\\QuickSort\\FileRandomTime\\FILE.dat", "r");
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
void Ghi1(int a[], int n)
{	
	FILE *fp;
	fp=fopen("E:\\TRUONGTHIDIEMQUYNH_61136433_DE04\\SAP XEP\\QuickSort\\FileRandomTime\\KQ.dat","w");
	for(int i=1; i<n;i++)
	{
		fprintf(fp,"%d\n",a[i]);
	}
		 
	
      fclose(fp); 
}

int main ()
{	
	double time_use;
	clock_t start,end;
	int a[MAX];
	int n,b,c;
	scanf("%d%d%d",&n,&b,&c);
	RanDom(a,n,b,c);
	Ghi(a,n);
	start = clock();	
	Doc(a,n);
	QuickSort(a,0,n-1);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC; 
	printf("Time thuc hien la:%f \n",time_use); 
	Ghi1(a,n);

	
}
	
