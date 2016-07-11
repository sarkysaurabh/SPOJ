#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
// lo == true, means number constructed till now is smaller at some pos or equal
// lo == false, means number got greater buddy 
ll dp[65][10];
ll cnt(int pos, int pre)
{
		if(pos == n)
		{
				return 1;
		}
		if(dp[pos][pre] != -1) return dp[pos][pre];
		int d;
		int npre,nlo;
		ll ans = 0;
		for(d=pre;d<10;++d)
		{
				ans = ans + (dp[pos+1][d] = cnt(pos+1,d));
		}
		return ans;
}
int main()
{
		int t;
		int z;
		int i;
		int j;
		cin>>t;
		while(t--)
		{
				for(i=0;i<65;++i)
						for(j=0;j<10;++j)
								dp[i][j] = -1;
				cin>>z>>n;
				cout<<z<<" "<<cnt(0,0)<<endl;
		}
}
