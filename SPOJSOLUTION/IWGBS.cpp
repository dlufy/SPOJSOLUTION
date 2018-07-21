#include<bits/stdc++.h>
using namespace std;
long long dp[20000];
bool ck(int i,int n)
{
	char s[n];
	for(int i=0;i<n;i++)
		s[i]='0';
	int in=n-1;
	while(i>0)
	{
		s[in]=char('0'+i%2);
		i=i>>1;
		in--;
	}
	for(int i=1;i<n;i++)
		if(s[i]=='0'&&s[i-1]=='0')
			return false;
	return true;
}
int main()
{
	int n;
	cin>>n;
	dp[1]=1;
	dp[2]=2;
	dp[3]=5;
	for(int i=4;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<dp[n];
}
