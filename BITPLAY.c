#include<bits/stdc++.h>
using namespace std;
int btod(string bin)
{
		string::reverse_iterator ir;
		int ans=0;
		for(ir=bin.rbegin();ir!=bin.rend();++ir)
		{
				ans+=(*ir-'0')*(1<<(ir-bin.rbegin()));		
		}
		return ans;
}
string dtob(int n)
{
		string bin,tmp;
		int rem;
		while(n)
		{	
				rem=n%2;
				n/=2;
				tmp=rem+'0';
				bin=tmp+bin;
		}
		return bin;

}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				int n,k;
				cin>>n>>k;
				n--;
				string num=dtob(n);
				//cout<<num<<" "<<count(num.begin(),num.end(),'1')<<endl;
				int s=count(num.begin(),num.end(),'1');
				if(k>=s) cout<<n<<endl;
				else
				{
						int cnt=s;
						string::reverse_iterator ir;
						ir=num.rbegin();
						//cout<<num<<endl;
						ir++;
						for(;ir!=num.rend();++ir)
						{
								if(*ir=='1') 
								{
										*ir='0';
										cnt--;
								}
								if(cnt==k) break;
						}
						if(cnt == k) cout<<btod(num)<<endl;
						else cout<<"-1"<<endl;
						//cout<<num<<endl;

				}
		}

}
