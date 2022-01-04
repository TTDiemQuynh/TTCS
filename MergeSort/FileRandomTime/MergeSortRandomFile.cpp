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
	fp=fopen("E:\\TRUONGTHIDIEMQUYNH_61136433_DE04\\SAP XEP\\MergeSort\\FileRandomTime\\FILE.dat","w");
	fprintf(fp,"%d\n",n);
	for(int i=0; i<n;i++)
	{
		fprintf(fp,"%d\t",a[i]);
	}
		 
	
      fclose(fp); 
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
void Doc(int a[], int n){
	
	FILE *f = fopen("E:\\TRUONGTHIDIEMQUYNH_61136433_DE04\\SAP XEP\\MergeSort\\FileRandomTime\\FILE.dat", "r");
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
	fp=fopen("E:\\TRUONGTHIDIEMQUYNH_61136433_DE04\\SAP XEP\\MergeSort\\FileRandomTime\\KQ.dat","w");
	for(int i=1; i<n;i++)
	{
		fprintf(fp,"%d\n",a[i]);
	}
		 
	
      fclose(fp); 
}

int main ()
{	double time_use;
	clock_t start,end;
	int a[MAX];
	int n,b,c;
	scanf("%d%d%d",&n,&b,&c);
	RanDom(a,n,b,c);
	Ghi(a,n);
	start = clock();	
	Doc(a,n);
	MergeSort(a,0,n-1);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC; 
	printf("Time thuc hien la:%f \n",time_use); 
	Ghi1(a,n);

	
}
	
