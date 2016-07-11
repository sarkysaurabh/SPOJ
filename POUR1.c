#include<bits/stdc++.h>
using namespace std;
int algo2(int a, int b, int c)
{
		int aa = min(a,b);
		int bb = max(a,b);
		a=aa;
		b=bb;
		int k = 0;
		int cnt = 0;
		while(k != c)
		{
				k+=a;
				cnt++;
				while(k>b && k!=c)
				{
						k-=b;
						cnt++;
				}
		}
		return cnt;
}
int algo1(int a, int b, int c)
{
		int aa = min(a,b);
		int bb = max(a,b);
		a=aa;
		b=bb;
		int k = 0;
		int cnt = 0;
		while(k != c)
		{
				k+=b;
				cnt++;
				while(k>c && k!=c)
				{
						k-=a;
						cnt++;
				}
		}
		return cnt;
}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				int a,b,c;
				cin>>a>>b>>c;
				if(c%__gcd(a,b) == 0 && (c <= a || c <= b))
				{
						printf("%d\n",min(algo1(a,b,c),algo2(a,b,c)));
						//printf("%d\n",algo1(a,b,c));
				}
				else puts("-1");
		}
}
