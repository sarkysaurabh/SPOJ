#include<bits/stdc++.h>
using namespace std;
string str1,str2;
#define MAX 4005
int dp[MAX][MAX];
int k;
int sol(int n, int m)
{
		if(dp[n][m] != -1) return dp[n][m];
		if(n == 0) return dp[n][m] = m*k;
		if(m == 0) return dp[n][m] = n*k;
		if(str1[n-1] == str2[m-1]) return dp[n][m] = sol(n-1,m-1);
		dp[n-1][m-1] = sol(n-1,m-1);
		dp[n-1][m] = sol(n-1,m);
		dp[n][m-1] = sol(n,m-1);
		return dp[n][m] = min(abs(str1[n-1]-str2[m-1]) + dp[n-1][m-1] , k+min(dp[n-1][m],dp[n][m-1]));
}
int main()
{
		cin>>str1>>str2;
		cin>>k;
		memset(dp,-1,sizeof(dp));
		cout<<sol(str1.size(),str2.size())<<endl;
}
