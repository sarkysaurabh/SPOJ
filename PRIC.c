#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define NEXT 1234567890
ull modmul(ull a, ull b, ull m)
{
		ull res=0;
		while(b)
		{
				if(b%2==1) res=(res+a)%m;
				a=(2*a)%m;
				b/=2;
		}
		return res;
}

ull modpow(ull a, ull b, ull m)
{
		ull res=1;
		while(b)
		{
				if(b%2==1) res=modmul(res,a,m);
				a=modmul(a,a,m);
				b/=2;
		}
		return res;

}
bool fermat(ull n)
{
		if(n<=1) return false;
		if(n==2 || n==3) return true;
		if(n%2==0 || n%3==0) return false;
		srand(time(NULL));
		int i=2;
		ull c;
		while(i--)
		{
				c=rand()%(n-1)+1;
				if(modpow(c,n-1,n)!=1)
				return false;
		}
		return true;
}

int main()
{
		ull a=1;
		ull i=200000;
		ull lim=pow(2,31);
		while(i--)
		{
				if(fermat(a)) cout<<"1";
				else cout<<"0";
				a=(a+NEXT)%lim;
		}
		/*cout<<fermat(3)<<endl;
		cout<<fermat(5)<<endl;
		cout<<fermat(7)<<endl;
		cout<<fermat(11)<<endl;
		cout<<fermat(12)<<endl;
		cout<<fermat(9223372036854775783)<<endl;
*/
}
