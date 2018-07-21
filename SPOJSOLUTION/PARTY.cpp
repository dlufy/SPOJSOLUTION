#include<bits/stdc++.h>
using namespace std;
pair<int,int> solve(int k,int n,int fee[],int fun[])
{
	int dp[n+5][k+5];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else if(j>=fee[i-1])
			dp[i][j]=max(dp[i-1][j],fun[i-1]+dp[i-1][j-fee[i-1]]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	int total=0;
	int i=n,j=k;
	int ff=dp[n][k];
	for(int i=0;i<=k;i++)
	{
		if(dp[n][i]==ff)
		{
			total=i;
			break;
		}
	}
	return make_pair(total,dp[n][k]);
}
int main()
{
	int m,n;
	while(cin>>m>>n&&m!=0&&n!=0)
	{
		int fun[n+10];
		int fee[n+10];
		for(int i=0;i<n;i++)
		cin>>fee[i]>>fun[i];
		pair<int,int> res=solve(m,n,fee,fun);
		cout<<res.first<<" "<<res.second<<"\n";
	}
}
