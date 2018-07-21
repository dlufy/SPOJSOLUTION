#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000000000000000
ll tr[200000][6];
ll dp[200000][6];
int main() {
	
	// your code here
	int tn=1;
	while(1)
	{
	int n;
	cin>>n;
	if(n==0)
		break;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<4;j++)
			cin>>tr[i][j];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(i==0||j==0||j==4)
				dp[i][j]=MAX;
		}
	}
	dp[1][1]=tr[1][1];
	dp[1][2]=tr[1][2];
	dp[1][3]=tr[1][2]+tr[1][3];
	dp[2][1]=tr[2][1]+tr[1][2];
	dp[2][2]=tr[2][2]+min(dp[2][1],min(dp[1][2],dp[1][3]));
	dp[2][3]=tr[2][3]+min(dp[2][2],min(dp[1][2],dp[1][3]));
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			ll cmp=MAX;
			dp[i][j]=tr[i][j];
			cmp=min(cmp,min(dp[i-1][j],dp[i-1][j+1]));
			cmp=min(cmp,min(dp[i-1][j-1],dp[i][j-1]));
			dp[i][j]+=cmp;
		}
	}
	cout<<tn<<". "<<dp[n][2]<<"\n";
	tn++;
	}
	return 0;
}
