#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int arr[MAX],st[3*MAX];
void build(int si, int ss, int se)
{
		if(ss == se)
		{
				st[si] = arr[ss];
				return;
		}
		int mid = (ss+se)/2;
		build(2*si,ss,mid);
		build(2*si+1,mid+1,se);
		st[si] = min(st[2*si] , st[2*si+1]);
}
int query(int si, int ss, int se, int qs, int qe)
{
		if(qs > se || qe < ss) return INT_MAX;
		if(qs <= ss && se <= qe) return st[si];
		int mid = (ss+se)/2;
		return min(query(2*si,ss,mid,qs,qe),query(2*si+1,mid+1,se,qs,qe));

}
int main()
{
		int t;
		cin>>t;
		int j = 1;
		while(t--)
		{
				int i;
				int n,q;
				//cin>>n>>q;
				scanf("%d %d",&n,&q);
				for(i=1;i<=n;++i)
						scanf("%d",arr+i);
				build(1,1,n);
				int l,r;
				printf("Scenario #%d:\n",j++);
				for(i=0;i<q;++i)
				{
						scanf("%d %d",&l,&r);
						printf("%d\n",query(1,1,n,l,r));
				}
		}
}
