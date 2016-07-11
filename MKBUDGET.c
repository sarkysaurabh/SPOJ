#include<bits/stdc++.h>
using namespace std;
#define ll int
int dp[30][300];
int arr[25];
int n;
int i;
int hire;
int mon;
int fire;
int lsol(int pos, int workers, int budget)
{
		if(pos == n) return dp[pos][workers] = budget;
		//if(dp[pos][workers] != -1) return dp[pos][workers];
		int req = arr[pos];
		int mbud = INT_MAX;
		int cbud = 0;
		if(workers == req) return dp[pos][workers] = lsol(pos+1,workers,budget+workers*mon);
		else if(workers > req)
		{
				cbud = budget;
				while(workers >= req)
				{
						mbud = min(mbud, dp[pos][workers] = lsol(pos+1,workers,cbud+workers*mon));
						cbud+=fire;
						workers--;
				}
				//return mbud;
				return dp[pos][workers+1] = mbud;
		}
		else
		{
				budget+=(req-workers)*hire;
				workers+=(req-workers);
				budget+=workers*mon;
				//return lsol(pos+1,workers,budget);
				return dp[pos][workers] = lsol(pos+1,workers,budget);
		}

}
ll sol(int pos, int workers, ll budget)
{
		if(pos == n) return budget;
		int req = arr[pos];
		ll mbud = INT_MAX;
		ll cbud = 0;
		if(workers == req) return sol(pos+1,workers,budget+workers*mon);
		else if(workers > req)
		{
				cbud = budget;
				while(workers >= req)
				{
						mbud = min(mbud, sol(pos+1,workers,cbud+workers*mon));
						cbud+=fire;
						workers--;
				}
				return mbud;
		}
		else
		{
				budget+=(req-workers)*hire;
				workers+=(req-workers);
				budget+=workers*mon;
				return sol(pos+1,workers,budget);
		}

}
void dpsol(void)
{
		int pos,workers;
		pos = 0;
		workers = arr[pos];
		dp[pos][workers] = workers*mon + workers*hire;
		int req;
		int w;
		int pre;
		pre = workers;
		for(pos = 0; pos < n; ++pos)
		{
				req = arr[pos];
				for(w=0;w=300;++w)
				{
						if(pos == 0)
						{
								dp[pos][w] = w*hire + w*mon;
						}
						else
						{
								if(w == req) dp[pos][w] = dp[pos-1][w] + w*mon;
								else if(w < req) dp[pos][w] = dp[pos-1][w] + (req-w)*(hire) + req*mon;
								else
								{
										dp[pos][w]
								}
						}
				}
		}


}
int main()
{
		cin>>n;
		int i,j;
		j=1;
		while(n)
		{
				memset(dp,-1,sizeof(dp));
				cin>>hire>>mon>>fire;
				for(i=0;i<n;++i)
						cin>>arr[i];
				cout<<"Case "<<j<<", cost = $"<<lsol(0,0,0)<<endl;
				cin>>n;
				j++;
		}

}
