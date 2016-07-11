#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long int
ll arr[MAX];
ll st[4*MAX];
void build(int si, int ss, int se)
{
		if(ss == se)
		{
				st[si] = arr[ss];
				return;
		}
		int mid = (ss+se)>>1;
		build(si<<1,ss,mid);
		build((si<<1)+1,mid+1,se);
		st[si] = st[si<<1] + st[(si<<1)+1];
}
ll query(int si, int ss, int se, int qs, int qe)
{
		if(qs > se || qe < ss || ss > se) return 0;												  
		if(qs <= ss && se <= qe) return st[si];
		int mid = (ss+se)>>1;
		if(qe <= mid) return query(si<<1,ss,mid,qs,qe);
		else if(qs > mid) return query(si<<1|1,mid+1,se,qs,qe);
		return query(si<<1,ss,mid,qs,qe) + query((si<<1)+1,mid+1,se,qs,qe);
}
void update(int si, int ss, int se, int qs, int qe)
{
		if(qe < ss || qs > se || ss > se) return;
		if(st[si] == se-ss+1) return;
		if(ss == se)
		{
				st[si] = sqrt(st[si]);
				return;
		}
		int mid = (ss+se)>>1;
		update(si<<1,ss,mid,qs,qe);
		update((si<<1)+1,mid+1,se,qs,qe);
		st[si] = st[si<<1] + st[(si<<1)+1];
}
void swap(ll *x, ll *y)
{
		ll tmp = *x;
		*x = *y;
		*y = tmp;
}
int main()
{
		int n;
		int i;
		int m;
		int cnt = 1;
		while(scanf("%d",&n) != EOF)
		{
				for(i=1;i<=n;++i)
						scanf("%lld",arr+i);
				build(1,1,n);
				scanf("%d",&m);
				ll j,a,b;
				printf("Case #%d:\n",cnt++);
				for(i=0;i<m;++i)
				{
						scanf("%lld%lld%lld",&j,&a,&b);
						if(a>b) swap(&a,&b);
						if(j)	printf("%lld\n",query(1,1,n,a,b));
						else	update(1,1,n,a,b);
				}
				cout<<"\n";
		}
}
