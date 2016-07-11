#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000
#define ull unsigned long long int
int lp[MAX];
void siever(void)
{
		int i,j;
		for(i=2;i<MAX;++i)
		{
				if(lp[i]==0)
				{
						for(j=i;j<MAX;++j)
						lp[j]=i;

				}
		}
}
ull divsum(ull n)
{
		ull pm,res;
		res=0;
		while(n!=1)
		{
				pm=lp[n];
						
		}
}
int main()
{
		siever();		
}
