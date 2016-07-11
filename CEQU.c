#include<bits/stdc++.h>
using namespace std;

int main() {

		int t;
		cin>>t;
		int i=1;
		while(t--)
		{
				int a,b,c;
				cin>>a>>b>>c;
				if(c%__gcd(a,b)==0) cout<<"Case "<<i<<": Yes"<<endl;
				else cout<<"Case "<<i<<": No"<<endl;
				i++;
		}

		return 0;
}
