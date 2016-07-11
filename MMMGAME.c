#include<bits/stdc++.h>
using namespace std;
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				int i;
				int n;
				cin>>n;
				int cnt = 0;
				int xr = 0;
				int tmp;
				for(i=0;i<n;++i)
				{
						cin>>tmp;
						xr ^= tmp;
						if(tmp == 1) cnt++;
				}
				if(cnt == n)
				{
						if(n&1) cout<<"Borther\n";
						else cout<<"John\n";
				}
				else
				{
						if(xr == 0) cout<<"Brother"<<endl;
						else cout<<"John"<<endl;
				}


		}
}
