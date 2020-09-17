#include<stdio.h>
#include<stdarg.h>
void f(int first, ...)
{
	int v[1000];
	va_list args;
	va_start(args,first);
	int ap = 0,nr = 0;
	//current = va_arg(args,int)
	for(int i=0;i<1000;i++)
		v[i]=0;
	int current = first;
		//n = va_arg(args,int)
	v[first]++;
		do
		{
			current = va_arg(args,int);
			if(current < 0)
				break;
			else
				v[current]++;
		}while(current >= 0);
		int max = v[0],p,i;
	for(i=0;i<10;i++)
		{ 
			/*if(max==v[i])
				if(i > p)
					p=i;*/

			if(v[i] > max)
				{max = v[i];
			p=i;}

		}

		printf("%d\n",p );

		
	va_end(args);



}

int main(int argc,char*argv[])
{
	f(1,1,2,1,2,-1);
	f(1,1,2,2,-4) ;
f(3,2,1,3,-100);
	return 0;
}
