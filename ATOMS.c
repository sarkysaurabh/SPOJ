#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
		int t;
		cin>>t;
		ll n,m,k;
		long double tmp;
		int ans;
		while(t--)
		{
				cin>>n>>k>>m;
				tmp = log(m) - log(n);
				//if(tmp == 0)
				//{
				//		cout<<2<<endl;
				//}
				//else
				{
						tmp/=log(k);
						ans = (int)tmp;
						cout<<ans<<endl;
				}

		}
}
