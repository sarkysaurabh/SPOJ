#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
string cad;
int sz;
int lp[MAX];
void siever(void)
{
		int j,i;
		lp[0]=lp[1]=1;
		for(i=2;i<MAX;++i)
		{
				if(lp[i] == 0)
				{
						for(j=i+i;j<MAX;j+=i)
						{
								lp[j]=1;
						}
				}
		}
}
bool isP(int n)
{
		if(lp[n] == 0) return true;
		return false;
}
bool isd[100][10][10][10];
int dp[100][10][10][10];
int solve(int pos, int sum, int l_low, int l_hi)
{
		if(pos == sz)
		{
				if(l_low<=l_hi && isP(sum)) return 1;
				return 0;
		}
		if(isd[sum][pos][l_low][l_hi]) return dp[sum][pos][l_low][l_hi];
		int d;
		int nl_low,nl_hi;
		int cnt = 0;
		int start;
		start = 0;
		for(d=start;d<10;++d)
		{
				nl_low = l_low;
				nl_hi = l_hi;
				if(d < cad[pos]-'0') nl_low = min(nl_low,pos);
				if(d > cad[pos]-'0') nl_hi = min(nl_hi,pos);
				cnt = cnt + (dp[sum+d][pos+1][nl_low][nl_hi] = solve(pos+1,sum+d,nl_low,nl_hi));
				//else cnt = cnt + (dp[sum+50+d][pos+1][nl_low][nl_hi] = solve(pos+1,sum+d,nl_low,nl_hi));
				//if((sz-pos)&1) cnt += solve(pos+1,sum-d,nl_low,nl_hi);
				//else cnt += solve(pos+1,sum+d,nl_low,nl_hi);
		}
		isd[sum][pos][l_low][l_hi] = true;
		dp[sum][pos][l_low][l_hi] = cnt;
		return cnt;
}
string tostr(int n)
{
		string res;
		char z;
		while(n)
		{
				z = n%10 + '0';
				res = z+res;
				n/=10;
		}
		sz = res.size();
		//res = z+res;
		return res;
}
int main()
{
		int t;
		siever();
		cin>>t;
		while(t--)
		{
				int a,b,aa,bb;
				cin>>a>>b;
				memset(isd,false,sizeof(isd));
				if(a > 0) cad = tostr(a-1);
				else cad = tostr(a);
				aa = solve(0,0,sz,sz);
				//cout<<"aa="<<aa<<endl;
				memset(isd,false,sizeof(isd));
				cad = tostr(b);
				bb = solve(0,0,sz,sz);
				//cout<<"bb="<<bb<<endl;
				cout<<bb - aa<<endl;
		}
}
