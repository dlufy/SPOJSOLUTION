#include<bits/stdc++.h>
using namespace std;
int mg[1000][1000];
int dp[1000][1000];
#define MAX 1000000000
bool check(int n,int m,int val)
{
	mg[0][0]=val;
	dp[0][0]=val;
	for(int i=1;i<m;i++)
	{
		dp[0][i]=dp[0][i-1]+mg[0][i];
		if(dp[0][i]<=0)
			dp[0][i]=-MAX;//mark it as block
	}
	for(int i=1;i<n;i++)
	{
		dp[i][0]=dp[i-1][0]+mg[i][0];
		if(dp[i][0]<=0)
			dp[i][0]=-MAX;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mg[i][j];
			if(dp[i][j]<=0)
				dp[i][j]=-MAX;
		}
	}
	return dp[n-1][m-1]>0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		int r=0;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>mg[i][j],r+=(abs(mg[i][j]));
		}
		int l=1;
		int tn=0;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(n,m,mid)==false)
			l=mid+1;
		else
			r=mid;
	}
	int i;
	for(i=l;i<=r;i++)
	{
		if(check(n,m,i))
		{
			cout<<i<<"\n";
			break;
		}
	}
	}
	return 0;
}
