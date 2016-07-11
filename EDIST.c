#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int dp[2001][2001];
int edit(int n, int m)
{
		if(dp[n][m] != -1) return dp[n][m];
		if(n == 0) return dp[n][m] = m;
		if(m == 0) return dp[n][m] = n;
		if(str1[n-1] == str2[m-1]) return dp[n][m] = edit(n-1,m-1);
		return dp[n][m] = 1+min(dp[n-1][m] = edit(n-1,m),min(dp[n-1][m-1] = edit(n-1,m-1), dp[n][m-1] = edit(n,m-1)));
}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				cin>>str1>>str2;
				memset(dp,-1,sizeof(dp));
				cout<<edit(str1.size(),str2.size())<<endl;
		}
}
