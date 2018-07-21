#include<bits/stdc++.h>
using namespace std;
int color[2000];
#define MAX 100000000
int fun_like_mcm(int n)
{
	int psum[200];
	psum[0]=color[0];
	for(int i=1;i<n;i++)
	psum[i]=psum[i-1]+color[i];
	int dp[200][200];
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=MAX;
			for(int k=i;k<j;k++)
			{
				int lc=(psum[k]-psum[i-1])%100;
				int rc=(psum[j]-psum[k])%100;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+lc*rc);
			}
		}
	}
	return dp[0][n-1];
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		scanf("%d",&color[i]);
		cout<<fun_like_mcm(n)<<endl;
	}
}
