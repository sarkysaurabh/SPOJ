#include<bits/stdc++.h>
using namespace std;
string tostr(int n)
{
		string str;
		int ld;
		while(n)
		{
				ld=n%10;
				string tp="";
				tp = ld + '0';
				str=tp+str;
				n/=10;

		}
		return str;
}
string sub(string str)
{
		string::iterator is;
		reverse(str.begin(),str.end());
		for(is=str.begin();is!=str.end();++is)
		{
				if(*is-'0'==0)
				{
						continue;
				}
				else
				{
						*is = *is-'0' -1 + '0';
						--is;
						break;
				}
		}
		while(is!=str.begin()-1)
		{
				*is=9+'0';
				--is;
		}
		reverse(str.begin(),str.end());
		string nstr;
		if(*str.begin()-'0'==0)
				str=str.substr(1);
		//str=nstr;
		return str;
}
string mul(string str, int n)
{
		int carry=0;
		int i;
		int tmp;
		int pr;
		for(i=str.size()-1;i>=0;--i)
		{
				tmp = str[i] - '0';		
				pr=tmp*n+carry;
				carry=0;
				if(pr>=10) carry=pr/10;
				tmp=pr%10;
				str[i] = tmp + '0';
		}
		if(carry>0) str=tostr(carry) + str;
		return str;


}
int main()
{
		int t=1024;
		while(t--)
		{
				string str,zero,one;
				zero='0';
				one='1';
				cin>>str;
				if(str == zero || str == one) cout<<str<<endl;
				else cout<<mul(sub(str),2)<<endl;
		}
}
