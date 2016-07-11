#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
int visited[MAX], dist[MAX];
vector<int> graph[MAX];
int bfs(int n, int src, int f)
{
		int i,j;
		int ans = 0;
		queue<int> mq;
		mq.push(src);
		int end,cur;
		memset(visited,0,sizeof(visited));
		memset(dist,0,sizeof(dist));
		while(!mq.empty())
		{
				cur = mq.front();
				mq.pop();
				for(i=0;i<graph[cur].size();++i)
				{
						if(visited[graph[cur][i]] == 0)
						{
								visited[graph[cur][i]] = 1;
								mq.push(graph[cur][i]);
								dist[graph[cur][i]] = dist[cur]+1;
								end = graph[cur][i];
						}
				}
				visited[cur] = 1;
		}
		if(f == 1) return dist[end];
		else return bfs(n,end,1);
}
int main()
{
		int n;
		int i;
		int a,b;
		cin>>n;
		for(i=0;i<n-1;++i)
		{
				cin>>a>>b;
				graph[a].push_back(b);
				graph[b].push_back(a);
		}
		cout<<bfs(n,a,0)<<endl;
}
