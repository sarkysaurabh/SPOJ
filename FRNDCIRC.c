#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
vector<pair<string,string > > vt;
map<string,int> mp;
int parent[MAX];
int size[MAX];
int findset(int i)
{
		while(i != parent[i])
		{
				parent[i] = parent[parent[i]];
				i = parent[i];
		}
		return i;
}
void unionset(int a,int b)
{
		int pa = findset(a);
		int pb = findset(b);
		if(pa != pb)
		{
				parent[pa] = pb;
				size[pb] += size[pa];
				cout<<size[pb]<<endl;
		}
		else
		{
				cout<<size[pb]<<endl;
		}
}
int main()
{
		ios_base::sync_with_stdio(false);
		int t;
		cin>>t;
		while(t--)
		{
				vt.clear();
				mp.clear();
				int n;
				int i;
				int no = 1;
				int u,v;
				string stra,strb;
				cin>>n;
				for(i=0;i<n;++i)
				{
						cin>>stra>>strb;
						vt.push_back(make_pair(stra,strb));
						mp[stra]++;
						mp[strb]++;
				}
				map<string,int>::iterator it;
				for(it=mp.begin();it!=mp.end();++it)
				{
						it->second = no;
						no++;
				}
				for(i=1;i<=mp.size();++i)
				{
						parent[i] = i;
						size[i] = 1;
				}
				for(i=0;i<vt.size();++i)
				{
						u = mp[vt[i].first];
						v = mp[vt[i].second];
						unionset(u,v);
				}
		}
}
