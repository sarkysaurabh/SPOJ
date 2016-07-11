#include<bits/stdc++.h>
using namespace std;
set<char> st;
multiset<char> mst;
string str;
void prints(set<char> st)
{
		set<char>::iterator is;
		for(is=st.begin();is!=st.end();++is)
		{
				cout<<*is;
		}
		cout<<" "<<st.size()<<endl;
}
void printm(multiset<char> mst)
{
		multiset<char>::iterator is;
		for(is=mst.begin();is!=mst.end();++is)
		{
				cout<<*is;
		}
		cout<<" "<<mst.size()<<endl;
}
int main()
{
		int m;
		scanf("%d",&m);
		//cout<<m<<" ";
		while(m)
		{
				getline(cin,str);
				getline(cin,str);
				string::iterator ib,ie;
				//for(ib=str.begin();ib!=str.end();++ib)
				//{
				//		if(*ib==' ') *ib='&';
				//}
				//cout<<"i got string=";
				//cout<<str<<endl;
				ib=ie=str.begin();
				int maxs=0;
				multiset<char>::iterator im;
				while(ie!=str.end())
				{
						st.insert(*ie);
						mst.insert(*ie);
						//prints(st);
						//printm(mst);
						if(st.size()>m)
						{
								while(st.size()!=m && ib!=ie)
								{
										im=mst.find(*ib);
										mst.erase(im);
										if(mst.find(*ib)==mst.end()) st.erase(*ib);
										++ib;

								}
						}
						if(mst.size() > maxs) maxs = mst.size();
						ie++;
						//prints(st);
						//printm(mst);
				}
				
				cout<<maxs<<endl;
				scanf("%d",&m);
				st.clear();
				mst.clear();
		}

}
