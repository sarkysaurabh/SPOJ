#include<bits/stdc++.h>
using namespace std;
string sum(string a, string b)
{
		char z = '0';
		while(a.size() > b.size())
		{
				b = '0' + b;		
		}
		while(b.size() > a.size())
		{
				a = '0' + a;		
		}
		int carry = 0;
		int tmp;
		int i;
		string ans = "";
		for(i=a.size()-1;i>=0;--i)
		{
				tmp = (a[i] - '0') + (b[i] - '0') + carry;
				carry = 0;
				z = tmp%10 + '0';
				carry = tmp/10;
				ans = z + ans;
		}
		while(carry > 0)
		{
				z = carry%10 + '0';
				ans = z + ans;
				carry/=10;
		}
		return ans;
}
string sub(string a, string b)
{
		while(a.size() > b.size())
		{
				b = '0' + b;		
		}
		while(b.size() > a.size())
		{
				a = '0' + a;		
		}
		string ans = "";
		char z;
		int tmp;
		int i;
		for(i=0;i<b.size();++i)
		{
				tmp = b[i] - '0';
				tmp=9-tmp;
				z = tmp + '0';
				b[i] = z;
		}
		ans = sum(a,b);
		ans = ans.substr(1);
		string st = "1";
		ans = sum(ans,st);
		z = '0';
		while(*ans.begin() == z)
		{
				ans = ans.substr(1);		
		}
		return ans;
}
int main()
{	
		string c,b,d;
		//cout<<sum(a,b)<<endl;
		string a,tmp,tmp2;
		int t;
		cin>>t;
		while(t--)
		{
				cin>>b>>c>>d;
				tmp = sum(c,c);
				tmp2 = sum(b,d);
				a = sub(tmp,tmp2);
				cout<<a<<endl;


				
		}
		//cin>>b>>c;
		//cout<<sub(b,c)<<endl;


}

