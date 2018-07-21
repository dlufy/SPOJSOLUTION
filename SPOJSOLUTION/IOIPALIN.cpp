#include<bits/stdc++.h>
using namespace std;
int lcs(int n,char x[],char y[])
{
	int dp[n+5][n+4];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(x[i-1]==y[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[n][n];
}
int main()
{
	int n;
	scanf("%d",&n);
	char s[n+5],s1[n+5];
	scanf("%s",&s);
	for(int i=0;i<n;i++)
		s1[i]=s[i];
	reverse(s,s+n);
	printf("%d",n-lcs(n,s,s1));
}
