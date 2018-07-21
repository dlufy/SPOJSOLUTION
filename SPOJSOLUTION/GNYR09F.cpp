#include<bits/stdc++.h>
using namespace std;
int dp[110][101][2];
int n,k;
int solve(int in,int cur_k,int prev_b)
{
	if(in==n)
		return (cur_k == k);
	if(dp[in][cur_k][prev_b]!=-1)
		return dp[in][cur_k][prev_b];
	dp[in][cur_k][prev_b]=solve(in+1,cur_k+prev_b,1);
	dp[in][cur_k][prev_b]+=solve(in+1,cur_k,0);
		return dp[in][cur_k][prev_b];
}
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int tn;
		cin>>tn>>n>>k;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)
				dp[i][j][0]=-1,dp[i][j][1]=-1;
		}
		int ans=solve(0,0,0);
		cout<<tn<<" "<<ans<<endl;
	}
}
