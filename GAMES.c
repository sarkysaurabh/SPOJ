#include<bits/stdc++.h>
using namespace std;
long long int ston(string str)
{
		long long int n;
		n=0;
		string::reverse_iterator ir;
		for(ir=str.rbegin();ir!=str.rend();++ir)
		{
				n+=(*ir-'0')*(pow(10,(ir-str.rbegin())));	
		}
		return n;

}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				double f;
				long long int n;
				long long int lim=10000;
				string str,nstr;
				cin>>str;
				if(str.find('.')==string::npos) str+=".0000";
				str+="0000";
				int pos;
				pos=str.find('.');
				nstr=str.substr(0,pos+5);
				string str1,str2;
				str1=nstr.substr(0,pos);
				str2=nstr.substr(pos+1,4);

				str=str1+str2;
				n=ston(str);
				cout<<lim/__gcd(n,lim)<<endl;
		}
		return 0;

}
