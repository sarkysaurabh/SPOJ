#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll dp[101][101];
int sol(int n, int k)
{
		if(dp[n][k] != -1) return dp[n][k];
		if(n <= 0) return dp[n][k] = 0;
		if(k >= n) return dp[n][k] = 0;
		if(k == n-1) return dp[n][k] = 1;
		if(k == n-2) return dp[n][k] = 2;
		return dp[n][k] = sol(n-1,k-1)+sol(n-1,k+1);
}
int main()
{
		int n,k;
		memset(dp,-1,sizeof(dp));
		int i;
		dp[1][0]=2;
		dp[2][0]=3;
		for(i=3;i<=100;++i)
		{
				dp[i][0] = dp[i-1][0]+dp[i-2][0];
		}
		cin>>n>>k;
		cout<<sol(n,k)<<endl;
}
