#include<bits/stdc++.h>
using namespace std;
#define MAX 10003
int parent[MAX];
int cost[MAX];
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
		int t;
		cin>>t;
		int c = 1;
		while(t--)
		{
				int n;
				int m;
				int i;
				int u;
				int v;
				int p;
				map<int,long long int> mp;
				vector<long long int> vt;
				map<int,long long int>::iterator it;
				vector<long long int>::iterator is;
				memset(parent,-1,sizeof(parent));
				
				cin>>n>>m;
				for(i=1;i<=n;++i)
				{
						cin>>cost[i];
						parent[i] = i;
				}
				for(i=0;i<m;++i)
				{
						cin>>u>>v;
						unionset(u,v);
				}
				for(i=1;i<=n;++i)
				{
						p = findset(i);
						mp[p] += cost[i];
				}
				cout<<"Case "<<c<<": "<<mp.size()<<endl;
				c++;
				for(it=mp.begin();it!=mp.end();++it)
						vt.push_back(it->second);
				sort(vt.begin(),vt.end());
				for(is=vt.begin();is!=vt.end();++is)
						cout<<*is<<" ";
				cout<<endl;
		}
}
