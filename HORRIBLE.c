#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long int
ll st[MAX*13], lazy[MAX*13];
ll query(ll si, ll ss, ll se, ll qs, ll qe)
{
		if(qs > se || qe < ss || ss > se) return 0;
		if(lazy[si])
		{
				st[si] += lazy[si]*(se-ss+1);
				if(ss != se)
				{
						lazy[si*2] += lazy[si];
						lazy[si*2+1] += lazy[si];

				}
				lazy[si] = 0;
		}
		if(qs <= ss && se <= qe) return st[si];
		ll mid = (ss+se)/2;
		return query(si*2,ss,mid,qs,qe) + query(si*2+1,mid+1,se,qs,qe);
}
void update(ll si, ll ss, ll se, ll qs, ll qe, ll val)
{
		if(lazy[si])
		{
				st[si] += lazy[si]*(se-ss+1);
				if(ss != se)
				{
						lazy[si*2] += lazy[si];
						lazy[si*2+1] += lazy[si];
				}
				lazy[si] = 0;
		}
		if(qs > se || qe < ss || ss > se) return;
		if(qs <= ss && se <= qe) {
				st[si] += (se-ss+1)*val;
				if(ss != se)
				{
						lazy[si*2] += val;
						lazy[si*2+1] += val;
				}
				return;
		}
		ll mid = (ss+se)/2;
		update(si*2,ss,mid,qs,qe,val);
		update(si*2+1,mid+1,se,qs,qe,val);
		st[si] = st[si*2] + st[si*2+1];
}
int main()
{
		ll t;
		ll n,c;
		ll i;
		cin>>t;
		while(t--)
		{
				cin>>n>>c;
				//memset(lazy,0,sizeof(lazy));
				//memset(st,0,sizeof(st));
				for(i=0;i<MAX*4;++i)
						lazy[i]=st[i]=0;
				ll a,p,q,v;
				for(i=0;i<c;++i)
				{
						cin>>a;
						if(!a)
						{
								cin>>p>>q>>v;
								update(1,1,n,p,q,v);
						}
						else
						{
								cin>>p>>q;
								cout<<query(1,1,n,p,q)<<endl;
						}
				}
		}
		return 0;
}
