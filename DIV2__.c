#include<stdio.h>
#define MAX 1000006
int lp[MAX],ans[MAX];
int pr;
void siever(void)
{
		int i,j;
		for(i=2;i<MAX;++i)
		{
				if(lp[i] == 0)
				{
						for(j=i+i;j<MAX;j+=i)
						{
								if(lp[j] == 0) lp[j] = i;
								else lp[j]*=i;
						}
				}
		}
}
int main()
{
		siever();
		int i;
		int a;
		int tmp;
		int d1,d2;
		a = 0;
		for(i=2;i<MAX-5;++i)
		{
				if(lp[i] == i)
				{
						ans[a++]=i;
				}
		}
		for(i=107;i<a;i+=108)
				printf("%d\n",ans[i]);
}
