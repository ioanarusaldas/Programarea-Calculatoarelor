#include<stdio.h>
#include<string.h>
 int main()
 {
 	
 	int N,i=0,j,k,t;
 	char sir[1000],cuv[1000][50];
 
 	fgets(sir,1000,stdin);
 	char *p=strtok(sir,". ?!");

 	while(p!=NULL)
 	{

 		strcpy(cuv[i],p);
 		i++;
 		
 		p=strtok(NULL,". ?!");
 	}
 	//for(j=0;j<i;j++)
 	//	{printf("%s",cuv[j]);
 	//printf ("%s","1");
 	l1=strlen(cuv[j]);
 	l2=strlen(cuv[k]);
 	max=l1+l2;
 	for(j=0;j<i;j++)
 		for(k=j+1;k<i;k++)
 			{
 				if
 				l1=strlen(cuv[j]);
 				l2=strlen(cuv[k]);
 				if((l1+l2)>max)
 					max=l1+l2;
 			}
 		}

 	return 0;
}
 		