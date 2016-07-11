#include<bits/stdc++.h>
using namespace std;
#define MAX 100000009
int mp[MAX];
unordered_map<int,int> mpp;
int findset(int i)
{
		here:
		if(i>MAX)
		{
				while(i > MAX && i != mpp[i])
				{
						mpp[i] = mpp[mpp[i]];
						i = mpp[i];
				}
		}
		while(i < MAX && mp[i] < MAX && i != mp[i])
		{
				mp[i] = mp[mp[i]];
				i = mp[i];
		}
		if(i < MAX && i == mp[i]) return i;
		if(i >= MAX && mpp[i] == i) return i;
		goto here;
}
void unionset(int a, int b)
{
		int pa = findset(a);
		int pb = findset(b);
		if(pa != pb)
		{
				if(pa < MAX) mp[pa] = pb;
				else mpp[pa] = pb;
		}
}
int main()
{
		ios_base::sync_with_stdio(false);
		int n;
		int m;
		int u;
		int v;
		int i;
		cin>>n>>m;
		for(i=1;i<=n;++i)
		{
				if(i < MAX) mp[i] = i;
				else mpp[i] = i;
		}
		for(i=0;i<m;++i)
		{
				cin>>u>>v;
				unionset(u,v);
		}
		int cnt = 0;
		for(i=1;i<=n;++i)
		{
				if(i < MAX) {if(mp[i] == i) cnt++;}
				else {if(mpp[i] == i) cnt++;}
		}
		cout<<cnt<<endl;
}
