#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500000
void RanDom(int a[], int n, int b, int c)//b<=c
{
	srand((int)time(0));
	for (int i=0;i<n;i++)
		a[i]=b+rand()%(c-b+1);
}
void Ghi(int a[], int n)
{	
	FILE *fp;
	fp=fopen("FILE.dat","w");
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
void BubbleSort(int a[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=n-1;j>i;j--)
			if (a[j]<a[j-1])
				Swap(a[j],a[j-1]);
}
void Doc(int a[], int n){
	
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
void Ghi1(int a[], int n)
{	
	FILE *fp;
	fp=fopen("KQ.dat","w");
	for(int i=0; i<n;i++)
	{
		fprintf(fp,"%d\t",a[i]);
	}
      fclose(fp); 
}

int main ()
{	double time_use;
	clock_t start,end;
	int a[MAX];
	int n,b,c;
	printf("nhap so luong phan tu: ");
	scanf("%d",&n);
	printf("nhap khoang bac dau ");
	scanf("%d",&b);
	printf("nhap khoang ket thuc ");
	scanf("%d",&c);
	RanDom(a,n,b,c);
	Ghi(a,n);
	start = clock();	
	Doc(a,n);
	BubbleSort(a,n);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC; 
	printf("Time thuc hien la:%f \n",time_use); 
	Ghi1(a,n);

	
}
	
