#include<bits/stdc++.h>
using namespace std;
string cad;
int sz;
bool isP(int n)
{
		if(n==2||n==3||n==5||n==7||n==11||n==13||n==17||n==19||n==23||n==29||n==31||n==37||n==41||n==43) return true;
		return false;
}
bool isd[100][10][10][10];
int dp[100][10][10][10];
int solve(int pos, int sum, int l_low, int l_hi)
{
		if(pos == sz)
		{
				if(l_low<=l_hi && sum>0 && isP(sum)) return 1;
				return 0;
		}
		if(isd[sum+50][pos][l_low][l_hi]) return dp[50+sum][pos][l_low][l_hi];
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
				if((sz-pos)&1) cnt = cnt + (dp[sum-d+50][pos+1][nl_low][nl_hi] = solve(pos+1,sum-d,nl_low,nl_hi));
				else cnt = cnt + (dp[sum+50+d][pos+1][nl_low][nl_hi] = solve(pos+1,sum+d,nl_low,nl_hi));
				//if((sz-pos)&1) cnt += solve(pos+1,sum-d,nl_low,nl_hi);
				//else cnt += solve(pos+1,sum+d,nl_low,nl_hi);
		}
		isd[50+sum][pos][l_low][l_hi] = true;
		dp[sum+50][pos][l_low][l_hi] = cnt;
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
void memet(int vec[100][10][10][10], int val, size_t szz)
{
		int i,j,k,l;
		for(i=0;i<100;++i)
		{
				for(j=0;j<10;++j)
				{
						for(k=0;k<10;++k)
						{
								for(l=0;l<10;++l)
								{
										vec[i][j][k][l] = val;
								}
						}
				}
		}
}
int main()
{
		int t;
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
