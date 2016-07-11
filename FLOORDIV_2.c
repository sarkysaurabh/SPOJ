#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[1001];
ll grundy[1000000];
int gs(ll n)
{
		if(n == 0) return 0;
		if(n == 1) return 1;
		if(n == 2) return 2;
		if(n == 3) return 2;
		if(n == 4) return 3;
		if(n == 5) return 3;
		
		ll i = 6;
		while(i <= n)
		{
				if(i<=n && n <= i*2-1) return 0;
				i*=12;
		}
		i/=12;
		i*=2;
		ll a1,b1,a2,b2,a3,b3;
		
		a1 = i;
		b1 = 2*i - 1;
		
		a2 = 2*i;
		b2 = 2*a2 - 1;

		a3 = 4*i;
		b3 = a3 + b1;

		if(a1 <= n && n <= b1) return 1;
		else if(a2 <= n && n <= b2) return 2;
		else return 3;

}
int main()
{
		int t;
		cin>>t;
		int i;
		while(t--)
		{
				ll n;
				cin>>n;
				ll xr = 1;
				for(i=0;i<n;++i)
				{
						cin>>arr[i];
				}
				xr = gs(arr[0]);
				for(i=1;i<n;++i)
						xr = xr ^ gs(arr[i]);
				if(xr == 0) cout<<"Derek"<<endl;
				else cout<<"Henry"<<endl;



		}
}
