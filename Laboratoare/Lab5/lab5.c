#include <stdio.h>

void afisare(int n,int v[100])
{
	int i;
	for( i=0;i<n;i++)
		printf("%d ",v[i]);
}
int main()
{	
	int i, n ,v[100],y,poz,j;
	scanf("%d",&n);
	scanf("%d",&poz);
	scanf("%d",&y);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	
	for(j=n-1;j>=poz;j--)
	{ 
		v[j+1]=v[j];
					
		
					
	}
 v[poz]=y;
 n++;
		
	afisare(n,v);

}