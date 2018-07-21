#include <bits/stdc++.h>
using namespace std;

int main() {
	
	// your code here
while(1)
{
	int n;
	cin>>n;
	if(n==0)
		break;
	long long ans=0;
	for(int i=1;i<=n;i++)
	ans+=(i*1LL*(i*1LL));
	cout<<ans<<endl;
}
	return 0;
}
