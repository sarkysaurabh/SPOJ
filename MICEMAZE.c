#include<bits/stdc++.h>
using namespace std;
long long int dis[105][105];
int main()
{
		int n;
		int e;
		int t;
		int m;
		cin>>n>>e>>t>>m;
		int i;
		int u,v,w;
		int j;
		int k;
		for(i=0;i<101;++i)
		{
				for(j=0;j<101;++j)
				{
						if(i == j) dis[i][j] = 0;
						else dis[i][j] = INT_MAX;
				}
		}
		for(i=0;i<m;++i)
		{
				cin>>u>>v>>w;
				dis[u][v] = w;
		}
		//cout<<"ip-done\n";
		for(k=1;k<=n;++k)
		{
				for(i=1;i<=n;++i)
				{
						for(j=1;j<=n;++j)
						{
								dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
						}
				}
		}
		int cnt = 0;
		for(i=1;i<=n;++i)
		{
				if(dis[i][e] <= t) 
				{
						//cout<<"i="<<i<<endl;
						cnt++;
				}
		}
		/*for(i=1;i<=n;++i)
		{
				for(j=1;j<=n;++j)
				{
						cout<<dis[i][j]<<" ";
				}
				cout<<endl;
		}*/
		cout<<cnt<<endl;
}
