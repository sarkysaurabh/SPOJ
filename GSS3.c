#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define inf LLONG_MAX
#define ll long long int
struct node
{
		ll ls,rs,ms,ss;
} st[MAX*4];
ll arr[MAX] , sarr[MAX];
struct node merge(struct node n1, struct node n2, ll ss, ll se, ll mid)
{
		struct node res;
		res.ms = max(n1.ms,n2.ms);
		res.ms = max(n1.rs+n2.ls,res.ms);
		res.ls = n1.ls;
		res.rs = n2.rs;
		ll sum1 = n1.ss;
		ll sum2 = n2.ss;
		res.ls = max(res.ls,sum1+n2.ls);
		res.rs = max(res.rs,sum2+n1.rs);
		res.ss = sum1 + sum2;
		return res;
}
void build(ll si, ll ss, ll se)
{
		if(ss == se)
		{
				st[si].ls = st[si].rs = st[si].ms = st[si].ss = arr[ss]; 
				return;
		}
		ll mid = (ss+se)/2;
		build(si*2,ss,mid);
		build(si*2+1,mid+1,se);
		st[si] = merge(st[si*2],st[si*2+1],ss,se,mid);
}
struct node query(ll si, ll ss, ll se, ll qs, ll qe)
{	
		struct node res;
		res.rs = -inf;
		res.ls = -inf;
		res.ms = -inf;
		if(ss > se || qe < ss || qs > se) return res;
		if(qs <= ss && se <= qe) return st[si];
		ll mid = (ss+se)/2;
		if(qe <= mid) return query(si*2,ss,mid,qs,qe);
		else if(qs > mid) return query(si*2+1,mid+1,se,qs,qe);
		struct node n1 = query(si*2,ss,mid,qs,qe);
		struct node n2 = query(si*2+1,mid+1,se,qs,qe);
		if(n1.ms == res.ms) return n2;
		else if(n2.ms == res.ms) return n1;
		//printf("ss=%d se=%d mid=%d\n",ss,se,mid);
		return merge(n1,n2,max(qs,ss),min(qe,se),mid);
}
void update(ll si, ll ss, ll se, ll pos, ll val)
{
		if(ss > se || pos > se || pos < ss) return;
		if(ss == se)
		{
				arr[ss] = val;
				st[si].ls = st[si].rs = st[si].ms = st[si].ss = arr[ss]; 
				return;
		}
		ll mid = (ss+se)/2;
		if(pos <= mid) update(si*2,ss,mid,pos,val);
		else if(pos > mid) update(si*2+1,mid+1,se,pos,val);
		st[si] = merge(st[si*2],st[si*2+1],ss,se,mid);
		
}
int main()
{
		ll n;
		ll i;
		ll m;
		ll x;
		ll y;
		cin>>n;
		for(i=1;i<=n;++i)
		{
				cin>>arr[i];
				sarr[i] += sarr[i-1]+arr[i];
		}
		sarr[i+1] = sarr[i];
		build(1,1,n);
		scanf("%lld",&m);
		ll z;
		for(i=0;i<m;++i)
		{
				scanf("%lld %lld %lld",&x,&y,&z);
				if(x == 0) update(1,1,n,y,z);
				else printf("%lld\n",query(1,1,n,y,z).ms);
		}

}
