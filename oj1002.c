#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 33000000000
int main()
{
		int t;
		//cin>>t;
		scanf("%d",&t);
		int cnt=1;
		int a,b,w;
		int n,m;
		int i,j;
		int src;
		ll arr[505][505];
		int k;
		ll dis[505][505];
		while(t--)
		{
				//memset(arr,0,sizeof(arr));
				cin>>n>>m;
				for(i=0;i<505;++i)
				{
						for(j=0;j<505;++j)
								arr[i][j] = 0;
				}
				for(i=0;i<m;++i)
				{
						scanf("%d %d %d",&a,&b,&w);
						if(arr[a][b]) 
						{
								if(arr[a][b] > w)
								{
										arr[a][b] = w;
										arr[b][a] = w;
								}
						}
						else
						{
								arr[a][b] = w;
								arr[b][a] = w;
						}

				}
				//cin>>src;
				scanf("%d",&src);
				for(i=0;i<n;++i)
				{
						for(j=0;j<n;++j)
						{
								if(i == j) dis[i][j] = 0;
								else
								{
										if(arr[i][j]) dis[i][j] = arr[i][j];
										else dis[i][j] = -1;
								}
						}
				}
				for(k=0;k<n;++k)
				{
						for(i=0;i<n;++i)
						{
								for(j=0;j<n;++j)
								{
										if(dis[k][j] != -1 && dis[i][k] != -1)
										{
												if(dis[i][j] == -1) dis[i][j] = max(dis[i][k], dis[k][j]);
												else dis[i][j] = min(dis[i][j],max(dis[i][k] , dis[k][j]));
										}

								}
						}
				}
				printf("Case %d:\n",cnt++);
				for(i=0;i<n;++i)
				{
						if(dis[src][i] == -1) printf("Impossible\n");
						else printf("%lld\n",dis[src][i]);
				}
		}
}
