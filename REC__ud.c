#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long int
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
int phi(int n)
{
		int i;
		int div;
		int ans;
		ans=n;
		while(n!=1)
		{
				div=lp[n];
				ans/=div;
				ans*=div-1;
				while(n%div==0)
				{
						n/=div;
				}
		}
		return ans;
}
ll modexp(ll a, ll b, ll m)
{
		if(b==1) return a;
		ll res=1;
		while(b)
		{
				if(b&1) res=(res*a)%m;
				a=(a*a)%m;
				b/=2;
		}
		return res;
}
ll gcd(string s, ll m)
{
		ll res=0;
		int i;
		string::iterator is;
		for(is=s.begin();is!=s.end();++is)
		{
				i=*is-'0';
				res=((res*10)%m + i%m)%m;
		}
		return res;
}
int main()
{
		siever();		
		int t;
		cin>>t;
		while(t--)
		{
				string a,b,n;
				ll m;
				cin>>a>>b>>n>>m;
				ll aa,bb,nn;
				aa=gcd(a,m);
				bb=gcd(b,m);
				nn=gcd(n,m);
				ll an=modexp(aa,nn,
				)


		}
		return 0;
}
