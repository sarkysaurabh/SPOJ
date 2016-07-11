#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int main()
{
		double a,b;
		a = 1;
		b = 1-eps;
		printf("%d\n",(int)a);
		printf("%d\n",(int)b);
		

		printf("%d\n",(int)(a+eps));
		printf("%d\n",(int)(b+eps));
}
