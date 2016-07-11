#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int arr[MAX],bit[MAX];
int t,n,u,q;
void update1(int i, int val)
{
		for(;i<=n;i+=i&-i)
			bit[i]+=val;	
}
void update(int l, int r, int val)
{
		update1(l,val);
		update1(r+1,-val);
}
int query(int i)
{
		int m = 0;
		for(;i>0;i-=i&-i)
				m+=bit[i];
				
		return m;
}
int main()
{
		cin>>t;
		while(t--)
		{
				memset(bit,0,sizeof(bit));
				scanf("%d %d",&n,&u);
				int i;
				int l,r;
				int val;
				while(u--)
				{
						scanf("%d %d %d",&l,&r,&val);
						update(l+1,r+1,val);


				}
				scanf("%d",&q);
				while(q--)
				{
						scanf("%d",&i);
						printf("%d\n",query(i+1));
				}
		}
}

