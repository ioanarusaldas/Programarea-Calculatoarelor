#include<stdio.h>
#include<string.h>
typedef struct student{
	char nume[30];
	char prenume[30];
	int varsta;

}student;
int main()
{
	int i,N,j;
	scanf("%d",&N);
	student pers[N];
	for(i=0;i<N;i++)
		scanf("%s %s %d",pers[i].nume,pers[i].prenume,&pers[i].varsta);
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			{
				if(strcmp(pers[i].nume,pers[j].nume)==0)
					{
						if(strcmp(pers[i].prenume,pers[j].prenume)==0)
							if(pers[i].varsta>pers[j].varsta)
							{
								student aux=pers[i];
								pers[i]=pers[j];
								pers[j]=aux;
							}
						else if(strcmp(pers[i].prenume,pers[j].prenume)<0)
							{
							student aux1=pers[i];
							pers[i]=pers[j];
							pers[j]=aux1;
							}
					}
				else if(strcmp(pers[i].nume,pers[j].nume)>0)
						{
							student aux2=pers[i];
							pers[i]=pers[j];
							pers[j]=aux2;
						}
			}


for(i=0;i<N;i++)
	{printf("%s %s %d",pers[i].nume,pers[i].prenume,pers[i].varsta);
	printf("\n");}

return 0;
}