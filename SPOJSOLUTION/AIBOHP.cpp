#include<bits/stdc++.h>
using namespace std;
int fun1(string s,string s1,int n)
{
	int dp[n+1][n+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else if(s[i-1]==s1[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][n];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
	string s,s1,s2;
	cin>>s;
	s1=s;
	reverse(s.begin(),s.end());
	int n=s.length();
cout<<n-fun1(s,s1,n)<<endl;
}
}
