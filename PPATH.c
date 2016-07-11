#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int lp[MAX],primes[MAX];
int pr = 0;
vector<int> vt;
void siever(void)
{
		int i,j;
		pr = 0;
		for(i=2;i<MAX;++i)
		{
				if(lp[i] == 0)
				{
						primes[pr++]=i;
						if(i > 999 && i <= 9999) vt.push_back(i);
						for(j=i;j<MAX;j+=i)
								lp[j]=1;
				}

		}
}
int ck(int a, int b)
{
		if(a == b) return 0;
		int cnt = 0;
		while(a)
		{
				if(a%10 != b%10) cnt++;
				a/=10;
				b/=10;
		}
		return cnt;
}
int bfs(int src, int des)
{
		int dis[MAX];
		int par[MAX];
		int i;
		queue<int> q;
		memset(dis,-1,sizeof(dis));
		memset(par,-1,sizeof(par));
		dis[src]=0;
		par[src]=src;
		q.push(src);
		//cout<<"src="<<src<<" des="<<des<<endl;
		while(!q.empty())
		{
				int cur = q.front();
				q.pop();
				for(i=0;i<vt.size();++i)
				{
						int g = vt[i];
						if(dis[g] == -1 && ck(cur,g) == 1)
						{
								//cout<<"cur="<<cur<<" g="<<g<<endl;
								dis[g] = dis[cur]+1;
								q.push(g);
								par[g]=cur;
								if(g == des)
								{
										//cout<<"going to break\n";
										while(!q.empty()) q.pop();
										break;
								}
						}
				}
		}
		/*while(des != par[des])
		{
				cout<<des<<"->";
				des = par[des];
		}
		cout<<endl;*/
		return dis[des];
}
int main()
{
		siever();
		int t;
		cin>>t;
		while(t--)
		{	
				int a,b;
				cin>>a>>b;
				cout<<bfs(a,b)<<endl;
		}
}
