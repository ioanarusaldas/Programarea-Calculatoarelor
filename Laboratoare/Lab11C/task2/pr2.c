#include<stdio.h>
#include<string.h>
typedef struct deque{
	int top;
	char elements[1000][31]

}stiva1;
int main()
{
	int N,i,j;
	stiva1 stiva;
	char cuv[1000],op[1000];
	scanf("%d",&N);

for(i=0;i<N;i++)
{if(strcmp(op[i],"push")==0)
{
	stiva.top++;
	strcpy(stiva.elements[stiva.top],cuv[i]);
}
if(strcmp(op[i],"pop")==0)
{
	stiva.top--;

}
if(strcmp(op[i],"print")==0)
{
	for(j=0;j<stiva.top;j++)
		printf("%s\n",stiva.elements[j] );
}
}
return 0;
}