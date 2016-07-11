#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define inf 0x7fffffff
struct node
{
		int l,lf,r,rf,h,hf;
} st[MAX*4];
int arr[MAX];
struct node merge(struct node n1, struct node n2)
{
		int nxt,nxtf;
		if(n1.r == n2.l)
		{
				nxt = n1.r;
				nxtf = n1.rf + n2.lf;
		}
		else
		{
				nxt = n1.h
				nxtf = n1.hf-1;
		}
		struct node res;
		if(n1.hf > max(n2.hf,nxtf))
		{
				res.h = n1.h;
				res.hf = n1.hf;
		}
		else if(n2.hf > max(n1.hf,nxtf))
		{
				res.h = n2.h;
				res.hf = n2.hf;
		}
		else
		{
				res.h = nxt;
				res.hf = nxtf;
		}
		res.l = n1.l;
		res.lf = n1.lf;
		res.r = n2.r;
		res.rf = n2.rf;
		if(res.h == res.l) res.lf = res.hf;
		if(res.h == res.r) res.rf = res.hf;
		//printf("res (%d %d %d %d %d %d)-\n",res.l,res.lf,res.r,res.rf,res.h,res.hf);
		return res;

}
void build(int si, int ss, int se)
{
		if(ss > se) return;
		if(ss == se)
		{
				st[si].l  = st[si].r  = st[si].h  = arr[ss];	
				st[si].lf = st[si].rf = st[si].hf = 1;
				//printf("came in for ss=se=%d\n",ss);
				return;
		}
		int mid = (ss+se)/2;
		build(si*2,ss,mid);
		int i;
		//for(i=1;i<=7;++i)
		//{
		//printf("(%d %d %d %d %d %d)-",st[i].l,st[i].lf,st[i].r,st[i].rf,st[i].h,st[i].hf);
		//}
		//printf("\n");
		build(si*2+1,mid+1,se);
		//for(i=1;i<=7;++i)
		//{
		//printf("(%d %d %d %d %d %d)-",st[i].l,st[i].lf,st[i].r,st[i].rf,st[i].h,st[i].hf);
		//}
		//printf("\n");
		st[si] = merge(st[si*2],st[si*2+1]);
		//for(i=1;i<=7;++i)
		//{
		//printf("(%d %d %d %d %d %d)-",st[i].l,st[i].lf,st[i].r,st[i].rf,st[i].h,st[i].hf);
		//}
		//printf("\n");

}
struct node query(int si, int ss, int se, int qs, int qe)
{
		struct node res;
		res.lf = -inf;
		if(ss > se || qs > se || qe < ss) return res;
		if(qs <= ss && se <= qe)	return st[si];
		int mid = (ss+se)/2;
		if(qe <= mid)
				return query(si*2,ss,mid,qs,qe);
		else if(qs > mid)
				return query(si*2+1,mid+1,se,qs,qe);
		struct node n1 = query(si*2,ss,mid,qs,qe);
		struct node n2 = query(si*2+1,mid+1,se,qs,qe);
		if(n1.lf == -inf) return n2;
		if(n2.lf == -inf) return n1;
		return merge(n1,n2);
}
int main()
{
		int n,q;

		cin>>n;
		while(n)
		{
				cin>>q;
				int i;
				for(i=1;i<=n;++i)
						scanf("%d",arr+i);
				build(1,1,n);
				int x,y;
				for(i=0;i<q;++i)
				{
						scanf("%d %d",&x,&y);
						//if(x!=y) printf("%d\n",query(1,1,n,x,y).hf);
						//else printf("1\n");
						printf("%d\n",query(1,1,n,x,y).hf);
				}
				cin>>n;
		}
		//for(i=1;i<=7;++i)
		//{
		//printf("(%d %d %d %d %d %d)-",st[i].l,st[i].lf,st[i].r,st[i].rf,st[i].h,st[i].hf);
		//}
		/*struct node n1,n2,res;
		  n1.l = n1.r = n1.h = 1;
		  n2.l = n2.r = n2.h = 2;
		  n1.lf=n1.rf=n1.hf=1;
		  n2.lf=n2.rf=n2.hf=1;
		  printf("(%d %d %d %d %d %d)-\n",n1.l,n1.lf,n1.r,n1.rf,n1.h,n1.hf);
		  printf("(%d %d %d %d %d %d)-\n",n2.l,n2.lf,n2.r,n2.rf,n2.h,n2.hf);
		  res=merge(n1,n2);
		  printf("(%d %d %d %d %d %d)-\n",res.l,res.lf,res.r,res.rf,res.h,res.hf);
		 */
}
