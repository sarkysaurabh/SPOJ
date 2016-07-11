#include<bits/stdc++.h>
using namespace std;
string str;
struct node
{
		int lb,rb;
		//bool y;
};
struct node st[1000000];
void build(int si, int ss, int se)
{
		if(ss == se)
		{
				if(str[ss] == '(')
				{
						st[si].lb = 1;
						st[si].rb = 0;
						//st[si].y = true;
				}
				else
				{
						st[si].rb = 1;
						st[si].lb = 0;
						//st[si].y = true;
				}
				return;
		}
		int mid = (ss+se)/2;
		build(si*2,ss,mid);
		build(si*2+1,mid+1,se);
		int left = min(st[si*2].lb, st[si*2+1].rb);
		st[si].lb = st[si*2].lb + st[si*2+1].lb - left; 
		st[si].rb = st[si*2].rb + st[si*2+1].rb - left; 
}
void update(int si, int ss, int se, int idx)
{
		if(idx > se || idx < ss) return;
		if(ss == se)
		{
				if(str[idx] == '(')
				{
						str[idx] = ')';
						st[si].lb-=1;
						st[si].rb+=1;
				}
				else
				{
						str[idx] = '(';
						st[si].lb+=1;
						st[si].rb-=1;
				}
				return;
		}
		int mid = (ss+se)/2;
		if(ss <= idx && idx <= mid)
		{
				update(si*2,ss,mid,idx);
		}
		else
		{
				update(si*2+1,mid+1,se,idx);
		}
		int left = min(st[si*2].lb, st[si*2+1].rb);
		st[si].lb = st[si*2].lb + st[si*2+1].lb - left; 
		st[si].rb = st[si*2].rb + st[si*2+1].rb - left; 

}
int main()
{
		int t = 10;
		int j = 1;
		int i;
		while(t--)
		{
				int n;
				scanf("%d",&n);
				cin>>str;
				char c = 'z';
				str=c+str;
				build(1,1,n);
				int m;
				scanf("%d",&m);
				int k;
				printf("Test %d:\n",j++);
				for(i=0;i<m;++i)
				{
						scanf("%d",&k);
						if(k)
						{
								update(1,1,n,k);
						}
						else
						{
								if(st[1].lb == st[1].rb && str[1] == '(' && str[n] ==')')
								{
										if(st[1].lb == 0 && st[1].rb == 0)
												printf("YES\n");
										else printf("NO\n");
								}
								else printf("NO\n");
						}
				}

		}
}
