#include <stdio.h>
int main()
{
	FILE *f = fopen("data.in","rt");
	//FILE *g = fopen("data.out","wt");
	/*if(f==NULL)
	{
		fprintf(g, "ERROR %s",f );
		return -1;
	}*/
	int a[100],b[100],i,j,n1,n2,s;
	fscanf(f,"%d",&n1);
	//fscanf(f,"%d",&n2);
	for(i=0;i<n1;i++)
		fscanf(f,"%d",&a[i]);
	fscanf(f,"%d",&n2);
	for(j=0;j<n2;j++)
		fscanf(f,"%d",&b[j]);
	FILE *g = fopen("data.out","wt");
	s=n1+n2;
	fprintf(g,"%d\n",s);
	i=0;
	j=0;
	while((i<n1)&&(j<n2))
	{
		if(a[i]<b[j])
		{
			fprintf(g,"%d ",a[i]);
			i++;
		}
		else
		{
			fprintf(g,"%d ",b[j]);
			j++;
		}	
	}
	while(i<n1)
	{
		if(i==n1-1)
		{
			fprintf(g,"%d\n",a[i]);
			i++;
		}
		else
		{
		fprintf(g,"%d ",a[i]);
		i++;
		}	
	}
	while(j<n2)
	{
		if(j==n2-1)
		{
			fprintf(g,"%d\n",a[j]);
			i++;
		}
		else
		{

		fprintf(g,"%d ",b[j]);
		j++;

		}
	}
	fclose(f);
	fclose(g);
	return 0;
}


