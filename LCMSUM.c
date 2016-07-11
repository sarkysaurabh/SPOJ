#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define ll long long int
ll res[MAX];
ll phi[MAX];
void pre(void)
{
		ll i,j;
		for(i=1;i<MAX;++i)
		phi[i] = i;
		for(i=2;i<MAX;++i)
		{
				if(phi[i]==i)
				{
						for(j=i;j<MAX;j+=i)
						{
								phi[j]/=i;
								phi[j]*=i-1;
						}
				}
		}
		for(i=1;i<MAX;++i)
		{
				for(j=i;j<MAX;j+=i)
				res[j] += phi[i]*i; 
		}
}
int main()
{
		//clock_t start,end;
		//start = clock();
		pre();
		//end = clock();
		//double time_used = (double)(end-start)/CLOCKS_PER_SEC;
		//cout<<time_used<<endl;
		int t;
		scanf("%d",&t);
		while(t--)
		{
				int n;
				scanf("%d",&n);
				res[n]+=1;
				res[n]/=2;
				res[n]*=n;
				printf("%Ld\n",res[n]);
		}
		return 0;
}
