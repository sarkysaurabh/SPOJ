#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
ull modmul(ull a, ull b, ull c)
{
		ull res=0;
		a%=c;
		b%=c;
		while(b)
		{
				if(b%2==1) res=(res+a)%c;
				a=(a*2)%c;
				b/=2;
		}
		return res%c;
}
ull power(ull a, ull p, ull mod)
{
		ull res=1;
		a%=mod;
		while(p)
		{
				if(p%2==1) res=modmul(res,a,mod);
				a=modmul(a,a,mod);
				p/=2;
		}
		return res;
}
bool fermat(ull p)
{
		srand(time(NULL));
		ull c;
		int i=2;
		if(p%2==0 || p%3==0) return false;
		while(i--)
		{
				c=rand()%(p-1)+1;
				
				

				if(power(c,p-1,p)%p!=1)
				{
						return false;
				}
		}
		return true;
}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				ull n;
				cin>>n;
				if(n==2 || n==3)
				{
						cout<<"YES"<<endl;
						continue;
				}
				if(fermat(n)) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
		}
		return 0;
}
