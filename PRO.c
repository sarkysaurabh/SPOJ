#include<bits/stdc++.h>
using namespace std;
#define ll long long int
multiset<int> mt;
multiset<int>::iterator it;
int main()
{
		int n;
		int i;
		int j;
		int tmp;
		int k;
		ll sum = 0;
		cin>>n;
		for(i=0;i<n;++i)
		{
				cin>>k;
				for(j=0;j<k;++j)
				{
						cin>>tmp;
						mt.insert(tmp);
				}
				it = mt.end();
				it--;
				sum += (*it - *mt.begin());
				mt.erase(it);
				mt.erase(mt.begin());
		}
		cout<<sum<<endl;
}
