#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define MOD 1000000007
int lp[MAX];
void siever(void)
{
		int i,j;
		for(i=2;i<MAX;++i)
		{
				if(lp[i]==0)
				{
						for(j=i;j<MAX;j+=i)
								lp[j]=i;
				}
		}
}
long long int power(long long int a, long long int b)
{
		long long int res,base;
		base=a%MOD;
		res=1;
		while(b)
		{
				if(b%2==1) res=((res%MOD) * (base%MOD))%MOD;
				base=(base*base)%MOD;
				b/=2;
		}
		return res;
}
int main()
{
		siever();
		map<long long int,long long int> mp;
		long long int res=1;
		long long int tmp,div;
		vector<int> vt(100000);
		for(int i=0;i<100000;++i,vt[i]=0);
		vt[0]=1;
		for(int i=1;i<=50000;++i)
		{
				tmp=i;
				while(tmp!=1)
				{
						div=lp[tmp];
						res=((res%MOD) * power(mp[div]+1,MOD-2)%MOD)%MOD;
						mp[div]++;
						res=(res*((mp[div]+1)%MOD))%MOD;
						tmp/=div;
				}
				vt[i]=res;
		}
		int t;
		cin>>t;
		while(t--)
		{
				int n;
				cin>>n;
				cout<<vt[n]<<endl;
		}
}
