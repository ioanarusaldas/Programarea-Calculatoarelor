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
	int n,m,i,j,min,max,a[maxi][maxi];
	scanf("%d",&n);
	scanf("%d",&m);
	citire(a,n,m);
	for(i=0;i<n;i++)
		//for(j=0;j<m;j++)
		{
			if(i%2==0)
			{
				min=a[i][0];
				for(j=0;j<m;j++)
					if(a[i][j]<min)
						min=a[i][j];
					printf("%d: min = %d\n",i+1,min);
					//printf(": min = ");
					//printf("%d\n",min);

			}


			if(i%2!=0)
			{
				max=a[i][0];
				for(j=0;j<m;j++)
					if(a[i][j]>max)
						max=a[i][j];
					printf("%d: max = %d\n",i+1,max);
					//printf("%d",i+1);
					//printf(": max = ");
					//printf("%d\n",max);


			}

		}	
		return 0;


}