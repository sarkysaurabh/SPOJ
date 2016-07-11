#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int st[MAX*4], lazy[MAX*4];
void update(int si, int ss, int se, int qs, int qe)
{
		if(lazy[si])
		{
				st[si] = (se-ss+1) - (st[si]);
				if(ss != se)
				{
						if(lazy[si*2]) lazy[si*2] = 0;
						else lazy[si*2] = 1;
						if(lazy[si*2+1]) lazy[si*2+1] = 0;
						else lazy[si*2+1] = 1;
				}
				lazy[si] = 0;
		}
		if(qs > se || qe < ss || ss > se) return;
		if(qs <= ss && se <= qe) 
		{
				st[si] = (se-ss+1) - (st[si]);
				if(ss != se)
				{
						if(lazy[si*2]) lazy[si*2] = 0;
						else lazy[si*2] = 1;
						if(lazy[si*2+1]) lazy[si*2+1] = 0;
						else lazy[si*2+1] = 1;
				}
				return;
		}
		int mid = (ss+se)/2;
		//if(qs > mid) update(si*2+1,mid+1,se,qs,qe);
		//else if(qe <= mid) update(si*2,ss,mid,qs,qe);
		//else
		{
				update(si*2+1,mid+1,se,qs,qe);
				update(si*2,ss,mid,qs,qe);
		}
		st[si] = st[si*2] + st[si*2+1];
}
int query(int si, int ss, int se, int qs, int qe)
{
		if(qs > se || qe < ss || ss > se) return 0;
		if(lazy[si])
		{
				st[si] = (se-ss+1) - (st[si]);
				if(ss != se)
				{
						if(lazy[si*2]) lazy[si*2] = 0;
						else lazy[si*2] = 1;
						if(lazy[si*2+1]) lazy[si*2+1] = 0;
						else lazy[si*2+1] = 1;
				}
				lazy[si] = 0;
		}
		if(qs <= ss && se <= qe) return st[si];
		int mid = (ss+se)/2;
		return query(si*2,ss,mid,qs,qe) + query(si*2+1,mid+1,se,qs,qe);
}
void print(void)
{
		int i,j;
		printf("st = ");
		for(i=1;i<=7;++i)
				printf("%d ",st[i]);
		printf("\n lazy = ");
		for(i=1;i<=7;++i)
				printf("%d ",lazy[i]);
		printf("\n");

}
int main()
{
		int n,m;
		cin>>n>>m;
		memset(st,0,sizeof(st));
		memset(lazy,0,sizeof(lazy));
		int i; 
		int x,y,z;
		for(i=0;i<m;++i)
		{
				scanf("%d %d %d",&z,&x,&y);
				if(z) printf("%d\n",query(1,1,n,x+1,y+1));
				else update(1,1,n,x+1,y+1);
				//print();

		}

}
