#include<stdio.h>
#include<string.h>
long long fun(char s1[],char s2[])
{
	int n1=strlen(s1);
	int n2=strlen(s2);
	long long dp[n1+5][n2+4];
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			if(i==0||j==0)
				dp[i][j]=(i+j);
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	return dp[n1][n2];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<fun(s1,s2);
}
