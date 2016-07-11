#include<bits/stdc++.h>
using namespace std;
vector<string> vt;
string mul(string str)
{
		int n;
		string tmp;
		string::iterator is;
		is=str.end();
		is--;
		int carry=0;
		int t;
		while(is!=str.begin()-1)
		{
				n=*is-'0';
				n=n*5+carry;
				carry=n/10;
				n%=10;
				char c = n+'0';
				tmp=c+tmp;
				is--;

		}
		while(carry)
		{
				char c=carry%10+'0';
				tmp=c +tmp;
				carry/=10;
		}
		return tmp;
}
int main()
{
		int t;
		int i,j;
		string str="1";
		vt.push_back(str);
		for(i=1;i<=1000;++i)
		{
				str=mul(str);
				vt.push_back(str);
				//cout<<str<<endl;
		}
		scanf("%d",&t);
		while(t--)
		{
				int n;
				scanf("%d",&n);
				//string ans = vt[n-1];
				int p = n - 1 - vt[n-1].size();
				if(n!=1) printf("0.");
				if(p>0)
				{
						while(p--) 
						printf("0");
				}
				cout<<vt[n-1]<<"\n";

		}

		return 0;
}
