#include<stdio.h>
#include<string.h>
 int main()
 {
 	
 	int N,i,j,k,t;
 	char sir[50][50],aux[50];
 	scanf("%d",&N);
 	for(t=0;t<N;t++)
 	scanf("%s",sir[t]);

 	//char *p=strtok(sir,". ?!");
 	for(i=0;i<N;i++)
 		for(j=i+1;j<N;j++)
 			if(strcmp(sir[i],sir[j])>0)
 			{
 				strcpy(aux,sir[i]);
    			strcpy(sir[i],sir[j]);
    			strcpy(sir[j],aux);

			}
	for(k=0;k<N;k++)
		printf("%s\n",sir[k]);
	return 0;

 }