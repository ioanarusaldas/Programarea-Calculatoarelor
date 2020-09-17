#include <stdio.h>
int main()
{
	FILE *f = fopen("data.in","rb");
	int n,v[1000],s=0;
	fseek(f,0,SEEK_END);
	n=ftell(f);
	fseek(f,0,SEEK_SET);
	fread(v,sizeof(int),n/sizeof(int),f);
	fclose(f);
	FILE *g = fopen("data.out","wt");
	int i;
	for(i=0;i<=n/sizeof(int);i++)
		s=s+v[i];
	fprintf(g, "%d\n",s );
	fclose(g);
	return 0;

}