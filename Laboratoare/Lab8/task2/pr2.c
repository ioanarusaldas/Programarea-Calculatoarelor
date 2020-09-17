#include <stdio.h>
int f(int a)
{
	int ok=0;
	if(a%2==0)
		ok=1;
	return ok;

}
void filter (int (*f) (int), int *v, int *n)
{ 
	int i,j,a;
 	for(i=0;i<*n;i++)
 	{
		a=*(v+i);
 		if(f(a)==0)
 		{
			for(j=i;j<*n;j++)
 				*(v+j)=*(v+j+1);
 			*n=*(n-1);

}
	}

	for(i=0;i<*n;i++)
		printf("%d", v[i]);
	return;
}
