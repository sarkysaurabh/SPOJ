#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[1001];
ll grundy[1000000];
int gs(ll n)
{
		if(n == 0) return 0;
		ll i = 6;
		while(i <= n)
		{
				if(i<=n && n <= i*2-1) return 0;
				i*=12;
		}
		multiset<int> mt;
		multiset<int>::iterator it;
		mt.insert(gs(n/2));
		mt.insert(gs(n/3));
		mt.insert(gs(n/4));
		mt.insert(gs(n/5));
		mt.insert(gs(n/6));
		int ret = 0;
		while(mt.find(ret) != mt.end())
				ret++;
		return ret;
}
int main()
{
		/*int t;
		cin>>t;
		int i;
		while(t--)
		{
				for(i=0;i<n;++i)
						cin>>arr[i];

		}*/
		int i;
		for(i=1;i<=1000;++i)
				cout<<gs(i)<<endl;
}
