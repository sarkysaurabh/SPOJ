#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
struct node
{
		int m1,m2;
};
int arr[MAX];
void build(struct node st[], int si, int ss, int se)
{
		if(ss == se)
		{
				st[si].m1 = arr[ss];
				st[si].m2 = INT_MIN;
				return;
		}
		int mid = (ss+se)/2;
		build(st,si*2,ss,mid);
		build(st,si*2+1,mid+1,se);
		//st[si] = max(st[si*2],st[si*2+1]);
		int tarr[] = {st[si*2].m1 , st[si*2].m2, st[si*2+1].m1, st[si*2+1].m2};
		sort(tarr,tarr+4);
		st[si].m1 = tarr[3];
		st[si].m2 = tarr[2];
}
struct node query(struct node st[], int si, int ss, int se, int qs, int qe)
{
		struct node tp,tpp;
		tp.m1 = tp.m2 = INT_MIN;
		if(qs > se || qe < ss) 
		{
		
				return tp;
		}
		if(qs <= ss && qe >= se) return st[si];
		int mid = (ss+se)/2;
		tp = query(st,si*2,ss,mid,qs,qe);
		tpp = query(st,si*2+1,mid+1,se,qs,qe);
		int tarr[] = {tp.m1 , tp.m2, tpp.m1, tpp.m2};
		sort(tarr,tarr+4);
		tp.m1 = tarr[3];
		tp.m2 = tarr[2];
		return tp;

}
void update(struct node st[], int si, int ss, int se, int idx, int val)
{
		if(idx > se || idx < ss) return;
		if(ss == se)
		{
				arr[idx] = val;
				st[si].m1 = val;
				return;
		}
		int mid = (ss+se)/2;
		if(idx <= mid)
		{
				update(st,si*2,ss,mid,idx,val);
		}
		else
		{
				update(st,si*2+1,mid+1,se,idx,val);
		}
		int tarr[] = {st[si*2].m1 , st[si*2].m2, st[si*2+1].m1, st[si*2+1].m2};
		sort(tarr,tarr+4);
		st[si].m1 = tarr[3];
		st[si].m2 = tarr[2];

}
int main()
{
		int n;
		scanf("%d",&n);
		int N = 2*pow(2,(ceil(log2(n))));
		struct node st[N];
		//cout<<"give no of qs"<<endl;
		int i;
		for(i=1;i<=n;++i)
				scanf("%d",arr+i);
		build(st,1,1,n);
		int q;
		scanf("%d",&q);
		char g;
		int a,b;
		struct node ans;
		for(i=0;i<q;++i)
		{
				scanf(" %c %d %d",&g,&a,&b);
				if(g=='Q')
				{
						ans = query(st,1,1,n,a,b);
						printf("%d\n",ans.m1+ans.m2);
				}
				else
				{
						update(st,1,1,n,a,b);
				}
		}
		return 0;
}
