#include<bits/stdc++.h>
using namespace std;
int pr[2000];
#define mx 1000000007
void fun(int n,int k)
{
	int dp[k+10];
	for(int i=1;i<=k;i++)
	dp[i]=pr[i]==-1?mx:pr[i];
	for(int i=2;i<=k;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(pr[j]==-1||dp[,mi-j]==mx)
				continue;
			dp[i]=min(dp[i],dp[i-j]+pr[j]);
		}
	}
	if(dp[k]!=mx)
	cout<<dp[k]<<endl;
	else
	cout<<"-1\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=k;i++)
		cin>>pr[i];
		fun(n,k);
	}
}
