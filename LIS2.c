#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second

vector<pii> vt;
int dp[MAX], sz;
pii c[MAX];

bool operator > (const pii &lhs, const pii &rhs)
{
	    return lhs.fi > rhs.first and lhs.se > rhs.se; 
};
bool operator < (const pii &lhs, const pii &rhs)
{
	    return lhs.fi < rhs.first and lhs.se < rhs.se; 
};

int bins(pii x)
{
	int l,r,mid,ans;
	ans=1;
	l=1;
	r=sz;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(c[mid]>x)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i,j,x,y;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>x>>y;
		vt.push_back({x,y});
	}
	dp[0] = 1;
	c[1] = vt[0];
	sz = 1;
	for(i=1;i<n;++i)
	{
		if(vt[i] < c[1])
		{
			c[1] = vt[i];
			dp[i] = 1;
		}
		else if(vt[i] > c[sz]) 
		{
			c[++sz] = vt[i];
			dp[i] = sz;
		}
		else
		{
			int k = bins(vt[i]);
			dp[i] = k;
			c[k] = vt[i];
		}
	}
	cout<<sz<<endl;
}
