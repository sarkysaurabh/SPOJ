#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll p;
ll ee(ll a, ll b, ll *x, ll *y)
{
		if(a==0) 
		{
				*x=0;
				*y=1;
				return b;
		}
		ll x1,y1,gcd;
		gcd=ee(b%a,a,&x1,&y1);
		*x=(y1-((b/a)*x1)%p+p)%p;
		*y=x1%p;
		return gcd;


}
ll modmul(ll a, ll b)
{
		if(b==1) return a;
		ll res=0;
		while(b)
		{
				if(b&1) res=(res+a)%p;
				a=(a*2)%p;
				b/=2;
		}
		return res;
}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				ll n;
				cin>>n>>p;
				ll pro=1;
				ll tmp;
				if(n>p)
				{
						/*pro=p-1;
						tmp=p;
						while(tmp!=n+1)
						{
								pro=(pro*tmp)%p;
								tmp++;
						}
						cout<<pro%p<<endl;*/
						cout<<"0"<<endl;
				}
				else if(p>n)
				{
						pro=1;
						tmp=n+1;
						while(tmp!=p)
						{
								tmp%=p;
								pro=(pro*tmp)%p;
								tmp++;
						}
						ll x,y;
						tmp=ee(pro,p,&x,&y);
						cout<<((p-1)*x)%p<<endl;
				}
				else
				{
						cout<<((n%p)*(p-1))%p<<endl;
				}
		}
		return 0;
}
