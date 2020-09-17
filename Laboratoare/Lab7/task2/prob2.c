#include <stdio.h>
#define maxi 1000
void citire(int a[maxi][maxi],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
}
int main()
{
	int n,m,i,j,min,max,a[n][m],b[m][n];
	scanf("%d",&n);
	scanf("%d",&m);
	citire(a,n,m);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			b[i][j]=a[n-j-1][i];
			
	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d",b[i][j]);
				if(j!=m-1)
					printf(" ");
			}
			printf("\n");
		}
return 0;
}