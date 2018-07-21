#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long dp[200000];
long long fun(int i)
{
	if(i>=n)
		return 0;
	if(dp[i]!=-1)
		return dp[i];
	
	if(i>=n-3)
	{
		dp[i]=0;
		for(int j=i;j<n;j++)
			dp[i]+=a[j];
		return dp[i];
	}
	return dp[i]=max(a[i]+fun(i+2),max(a[i]+a[i+1]+fun(i+4),a[i]+a[i+1]+a[i+2]+fun(i+6)));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]),dp[i]=-1;
		cout<<fun(0)<<"\n";
	}
}
