#include<bits/stdc++.h>
using namespace std;
int mg[1000][1000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>mg[i][j];
		}
	int dp[n][m];
	dp[n-1][m-1]=1;
	for(int i=m-2;i>=0;i--)
	{	
		dp[n-1][i]=dp[n-1][i+1]-mg[n-1][i];
		if(dp[n-1][i]<=0)
			dp[n-1][i]=1;
	}
	
	for(int i=n-2;i>=0;i--)
	{	
		dp[i][m-1]=dp[i+1][m-1]-mg[i][m-1];
		if(dp[i][m-1]<=0)
			dp[i][m-1]=1;
	}
	
	for(int i=n-2;i>=0;i--)
	{
		for(int j=m-2;j>=0;j--)
		{
			dp[i][j]=min(dp[i][j+1],dp[i+1][j])-mg[i][j];
			if(dp[i][j]<=0)
				dp[i][j]=1;
		}
	}
	/*cout<<"dp table \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<"ans ";*/
cout<<dp[0][0]<<"\n";
}
return 0;
}
