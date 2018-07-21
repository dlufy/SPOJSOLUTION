#include<bits/stdc++.h>
using namespace std;
int x[4000];
int y[4000];
int lcs(int x[],int y[],int n,int m)
{
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(x[i-1]==y[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[n][m];
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	int ans=0;
	int n,n1,n2;
	int i=0;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		x[i++]=n;
	}
	n1=i;
	while(1)
	{
		i=0;
		scanf("%d",&n);
		if(n==0)
			break;
		y[i++]=n;
		while(1)
		{
			scanf("%d",&n);
			if(n==0)
				break;
			y[i++]=n;
		}
		n2=i;
		ans=max(ans,lcs(x,y,n1,n2));
	}
	cout<<ans<<"\n";
	}
}
