#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
map<int,int> mp;
vector<pair<int,int > > vt;
int parent[MAX];
int findset(int i)
{
		while(i != parent[i])
		{
				parent[i] = parent[parent[i]];
				i = parent[i];
		}
		return i;
}
void unionset(int a, int b)
{
		int pa = findset(a);
		int pb = findset(b);
		if(pa != pb)
				parent[pa] = pb;
}
int main()
{
		int n;
		int m;
		int u;
		int v;
		cin>>n>>m;
		int i;
		for(i=0;i<m;++i)
		{
				cin>>u>>v;
				mp[u]++;
				mp[v]++;
				vt.push_back(make_pair(u,v));
		}
		map<int,int>::iterator it;
		int no = 0;
		for(it=mp.begin();it!=mp.end();++it)
		{
				no++;
				it->second = no;
		}
		int sz = mp.size();
		for(i=1;i<=sz;++i)
				parent[i] = i;
		for(i=0;i<vt.size();++i)
		{
				u = mp[vt[i].first];
				v = mp[vt[i].second];
				unionset(u,v);
		}
		int cnt = 0;
		for(i=1;i<=sz;++i)
		{
				if(parent[i] == i) cnt++;
		}
		//cout<<"cnt="<<cnt<<" sz="<<sz<<endl;
		cout<<n-sz+cnt<<endl;

}
