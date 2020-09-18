#include <stdio.h>
void afisare(int n,int v1[100])
{
	int i;
	for( i=0;i<=n;i++)
		if(v1[i]!=0)
		printf("numarul %d apare de %d ori \n",i,v1[i]);
}
int main()
{
	int n,v[1000],i;
	int v1[100]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	for(i=0;i<n;i++)
	{ v1[v[i]]++;

	}
	afisare(n,v1);
	return 0;
}