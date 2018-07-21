#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[1000][1000][3];
int fun(int i,int j,string mz[],int direction)
{
	if(i<0||j<0||i>=n||j>=m||mz[i][j]=='#')
		return 0;
	if(dp[i][j][direction]!=-1)
		return dp[i][j][direction];
	int cnt=0;
	if(mz[i][j]=='T')
		cnt++;
	if(direction)
		return dp[i][j][direction]=max(fun(i,j+1,mz,1),fun(i+1,j,mz,0))+cnt;
	else
		return dp[i][j][direction]=max(fun(i,j-1,mz,0),fun(i+1,j,mz,1))+cnt;
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,-1,sizeof dp);
		scanf("%d%d",&n,&m);
		string mz[n+5];
		for(int i=0;i<n;i++)
			cin>>mz[i];
		cout<<fun(0,0,mz,1)<<"\n";
	}
}
