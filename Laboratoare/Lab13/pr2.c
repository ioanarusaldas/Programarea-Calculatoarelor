#include<stdio.h>
#include<stdarg.h>
#include<string.h>
void calculus(char *first, ...)
{
	char v[1000];
	va_list args;
	int s;
	va_start(args,first);
	
	char current = first;
	i=0;

		//n = va_arg(args,int)
		do
		{

			current = va_arg(args,int);
			v[i]=current;
			i++;
			
			
		}while(current <= 6);
		for(i=1;i<=4;i++)
		if(first[i]=='+')
		{
			if(i==1);
			s=(v[1]-'0')+(v[2]-'0');
			if
		}
		
	va_end(args);



}

int main(int argc,char*argv[])
{
	return 0;
}