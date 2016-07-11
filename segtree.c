#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int arr[MAX],st[MAX];
void build(int si, int ss, int se)
{
		if(ss == se)
		{
				st[si] = arr[ss];
				return;
		}
		int mid  = (ss+se)/2;
		build(2*si,ss,mid);
		build(2*si+1,mid+1,se);
		st[si] = st[2*si] + st[2*si+1];
}
int query(int si, int ss, int se, int qs, int qe)
{
		if(qs <= ss && qe >= se)
		{
				return st[si];
		}
		if(qs > se || qe < ss) return 0;
		int mid = (ss+se)/2;
		return query(2*si,ss,mid,qs,qe) + query(2*si+1,mid+1,se,qs,qe);



}
void update(int si, int ss, int se, int idx, int val)
{
		if(ss == se)
		{
				arr[idx] += val;
				st[si] += val;
		}
		else
		{
				int mid  = (ss+se)/2;
				if(ss <= idx && idx <= mid)
				{
						update(2*si,ss,mid,idx,val);
				}
				else
				{
						update(2*si+1,mid+1,se,idx,val);
				}
				st[si] = st[2*si] + st[2*si+1];
		}
}
int main()
{
		int i;
		int n;
		cin>>n;
		for(i=1;i<=n;++i)
		{
				cin>>arr[i];
		}
		build(1,1,n);
		int q;
		cin>>q;
		for(i=0;i<q;++i)
		{
				int l,r;
				cin>>l>>r;
				cout<<query(1,1,n,l,r)<<endl;
				update(1,1,n,l,1);
		}
}
