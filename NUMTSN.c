#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int n;
string cad;
int dp[2][18][18][18][51];
inline int cnt(int i, int three, int six, int nine, bool tight)
{
		if(i == n)
		{
				if(three == six && six == nine && six > 0) return 1;
				return 0;
		}
		if(three >= 17 || six >= 17 || nine >= 17) return 0;
		int d;
		int ans = dp[tight][three][six][nine][i];
		if(ans != -1) return ans;
		else ans = 0;
		bool ntight, nisd;
		for(d=0;d<10;++d)
		{
				if(tight == true && d > cad[i]-'0') continue;

				if(tight == true && d == cad[i]-'0') ntight = true;
				else ntight = false;

				if(d == 3) ans = (ans%MOD + cnt(i+1,three+1,six,nine,ntight))%MOD;
				else if(d == 6) ans = (ans%MOD + cnt(i+1,three,six+1,nine,ntight))%MOD;
				else if(d == 9) ans = (ans%MOD + cnt(i+1,three,six,nine+1,ntight))%MOD;
				else ans = (ans%MOD + cnt(i+1,three,six,nine,ntight))%MOD;
		}
		dp[ntight][three][six][nine][i] = ans%MOD;
		return ans%MOD;

}
int ck(string str)
{
		int three,six,nine;
		three = six = nine = 0;
		int i;
		for(i=0;i<str.size();++i)
		{
				if(str[i] == '3') three++;
				else if(str[i] == '6') six++;
				else if(str[i] == '9') nine++;
		}
		if(three == six && six == nine && six) return 1;
		return 0;
}
int main()
{
		ios_base::sync_with_stdio(false);
		int t;
		cin>>t;
		while(t--)
		{
				string a,b;
				cin>>a>>b;
				ll aa,bb;
				int h;
				h = ck(a);
				cad = a;
				n = cad.size();
				memset(dp,-1,sizeof(dp));
				aa = cnt(0,0,0,0,1);
				cad = b;
				n = cad.size();
				memset(dp,-1,sizeof(dp));
				bb = cnt(0,0,0,0,1);
				cout<<(bb-aa+MOD+h)%MOD<<endl;
		}
}
