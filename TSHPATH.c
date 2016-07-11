#include<bits/stdc++.h>
using namespace std;
vector<string> vts;
vector<pair<int,int> > vt[10005];
#define ll long long int
bool visit[10005];
ll dis[10005];
priority_queue<pair<ll,ll> , vector<pair<ll,ll> > , greater<pair<ll,ll> > > pq;
#define INF 10000000000
int dist(string city1, string city2)
{
		int i;
		for(i=0;i<10005;++i)
				dis[i] = INF;
		vector<string>::iterator is;
		int src,dest;
		for(is=vts.begin();is!=vts.end();++is)
		{
				if(*is == city1) src = is-vts.begin();
				else if(*is == city2) dest = is-vts.begin();
		}
		memset(visit,false,sizeof(visit));
		dis[src]=0;
		int j;
		while(pq.size())
				pq.pop();
		pq.push(make_pair(0,src));
		pair<ll,ll> tmp;
		int curr;
		while(pq.size())
		{	
				tmp=pq.top();
				pq.pop();
				if(visit[tmp.second]) continue;
				if(tmp.second == dest) return tmp.first;
				curr = tmp.second;
				visit[curr] = true;
				int nxt;
				for(i=0;i<vt[curr].size();++i)
				{
						nxt = vt[curr][i].first;
						if(dis[curr]+vt[curr][i].second < dis[nxt])
						{
								dis[nxt] = dis[curr] + vt[curr][i].second;
								pq.push(make_pair(dis[nxt],nxt));
						}
				}
		}


}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				int n;
				cin>>n;
				vts.push_back("NULL");
				int i;
				for(i=1;i<=n;++i)
				{
						string city;
						cin>>city;
						vts.push_back(city);
						int j;
						int lim;
						cin>>lim;
						for(j=0;j<lim;++j)
						{
								int a,b;
								cin>>a>>b;
								vt[i].push_back(make_pair(a,b));
						}


				}
				int q;
				cin>>q;
				while(q--)
				{
						 
						string str1,str2;
						cin>>str1>>str2;
						cout<<dist(str1,str2)<<endl;
				}
				vts.clear();
				for(i=0;i<10005;++i)
						vt[i].clear();
		}
}
