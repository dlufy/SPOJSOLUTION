#include <bits/stdc++.h>
using namespace std;

int main() {
	
	// your code here
int t,n;
scanf("%d",&t);
while(t)
{
	t--;
	double a=0.0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
{	a+=n/(i*1.0);
}
	printf("%.9lf\n",a);
}
	return 0;
}
