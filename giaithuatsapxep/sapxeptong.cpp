#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
/* chu thich bien
a[MAX] mang 1 chieu
n chieu dai mang
m so phan tu cua mang
*/
int a[MAX],n,m;
/*Nhap du lieu tu ban phim*/
//nhap mang
void nhapphim(int a[], int n)
{
    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Cac phan tu cua mang: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
/*Nhap du lieu tu file co san*/
void docfile()
{
	/*sua duong dan*/
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
/*Nhap du lieu ngau nhien trong khoang [a,b]*/
//b<=c
void RanDom(int a[], int n) 
{
	int b,c;
	printf("nhap khoang [a,b]:\n");
	scanf("%d%d",&b,&c);
//	srand((int)time(0));
	for (int i=0;i<n;i++)
		a[i]=b+rand()%(c-b+1);
	printf("Mang Random la: ");	
	for(int i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
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
void Merge(int a[], int l, int m, int r) 
{ 	
    
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
  	for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
    i=0;
    j=0;
    k=l;
    
   while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
     while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
      while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    }
}

void MergeSort(int a[], int l, int r)
{
	if (l<r)
	{
		int t=(l+r)/2;
		MergeSort(a,l,t);
		MergeSort(a,t+1,r);
		Merge(a,l,t,r);
	}
}
void BubbleSort(int a[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=n-1;j>i;j--)
			if (a[j]<a[j-1])
				Swap(a[j],a[j-1]);
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
void In(int a[], int n)
{
	printf("\nket qua:");
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void Ghi(int a[], int n)
{	
	FILE *fp;
	/*sua duong dan*/
	fp=fopen("kq.dat","w");
	for(int i=0; i<n;i++)
	{
		fprintf(fp,"%d\n",a[i]);
	}
      fclose(fp); 
}
int main ()
{	
	int dl,sx,l,r,exit;
	clock_t start, end,start1, end1,start2, end2,start3, end3;
    double time_use,time_use1,time_use2,time_use3;
//	int luachon,exit;
	start = clock();
	start1 = clock();
	start2 = clock();
	start3 = clock();
	printf("====menu chon cach nhap du lieu====");
	printf("\n1.Nhap tu ban phim! \n2.Nhap tu file! \n3.Nhap ngau nhien trong khoang [a,b]! ");
	printf("\nNhap lua chon (chon 1,2,3):");
	scanf("%d",&dl);
	printf("Lua chon cua ban la :");
	switch(dl)
	{
		case 1:
				printf("Nhap tu ban phim!\n");
				printf("Nhap n: ");
				scanf("%d",&n);
				nhapphim(a,n);
			break;
		case 2:
			printf("Nhap tu file!");
			docfile();
			break;
		case 3:
			printf("Nhap ngau nhien trong khoang [a,b]!");
			printf("\nNhap n: ");
			scanf("%d",&n);
	      	RanDom(a,n);
	      	Ghi(a,n);
			break;
	// chua xu lý neu nhap khac 1,2,3 thi se bao nhap lai hoac thoat chuong trinh
	}
	do
	{	
		printf("\n====menu chon loai sap xep====\n");
		printf("1. QuickSort!\n");
		printf("2. MergeSort!\n");
		printf("3. BubbleSort!\n");
		printf("4. InsertSort!");
		printf("\nNhap lua chon: ");
		scanf("%d",&sx);
		printf("Lua chon cua ban la:");
		switch(sx)
		{
			case 1: 
				printf("QuickSort!\n");
				QuickSort(a,0,n-1);
				end = clock();
				time_use = (double)(end - start) / CLOCKS_PER_SEC; 
				In(a,n);
				printf("Time thuc hien QuickSort la:%f \n",time_use); 
				Ghi(a,n);
				break;
			case 2: 
				printf("MergeSort!\n");
				MergeSort(a,0,n-1);
				end1 = clock();
				time_use1 = (double)(end1 - start1) / CLOCKS_PER_SEC; 
				In(a,n);
				Ghi(a,n);
				printf("Time thuc hien MergeSort la:%f \n",time_use1);
				break;
			case 3: 
				printf("BubbleSort!\n");
				BubbleSort(a,n);
				end2 = clock();
				time_use2 = (double)(end2 - start2) / CLOCKS_PER_SEC;  
				In(a,n);
				printf("Time thuc hien BubbleSort la:%f \n",time_use2);
				Ghi(a,n);
				break;
			case 4: 
				printf("InsertSort!\n");
				InsertSort(a,n);
				end3 = clock();
				time_use3 = (double)(end3 - start3) / CLOCKS_PER_SEC; 
				In(a,n);
				printf("Time thuc hien InsertSort la:%f\n",time_use3); 
				Ghi(a,n);
				break;
		}		
		printf("Ban co muon lam tiep<0: thoat>: ");
		scanf("%d",&exit);
	}while(!(exit == 0));
	return 0;

}

