#include<stdio.h>
#include<stdlib.h>
void push_back(int *v,int *len,int *capacity,int nr)
{
	if ((*len)<(*capacity))
	{
		v[(*len)]=nr;
		(*len)++;
	}
	else
	{
		*capacity=(*capacity)*2;
		v[(*len)]=nr;
		v=realloc(v,(*capacity)*sizeof(int));

		(*len)++;
	}
}
int main()
{
	int capacity=5,len=0,nr;
	scanf("%d",&nr);
	int *v=calloc(capacity,sizeof(int));
	while(nr>0)
	{
	push_back(v,&len,&capacity,nr);
	scanf("%d",&nr);
	}
	for(int i=0;i<len;i++)
		printf("%d", v[i]);
	return 0;
}