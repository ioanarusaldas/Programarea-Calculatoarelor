#include <stdio.h>

void inv(int *v,int n)
{
	int i,*p1,*p2,aux;
	p1=v;
	p2=(v+(n-1));
	for(i=0;i<n/2;i++)
		{   
			aux=*(p1+i);
			*(p1+i)=*(p2-i);
			*(p2-i)=aux;
			
		}

}
int main()
{
	int v[100],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	inv(v,n);
	for(i=0;i<n;i++)
		printf("%d ",v[i]);
	printf("\n");
	return 0;
}