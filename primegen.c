#include<stdio.h>
#define MAX 10000000
int primes[MAX];
int pr;
int lp[MAX];
void siever(void)
{
		int i,j;
		pr=0;
		for(i=2;i<MAX;++i)
		{
				if(lp[i]==0)
				{
						primes[pr++]=i;
						for(j=i*2;j<MAX;j+=i)
						lp[j]=i;
				}
		}
}
int main()
{
		siever();
		int i;
		for(i=0;i<pr;++i)
		printf("%d\n",primes[i]);
		return 0;
}
