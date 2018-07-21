#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000
int p[200][200];
int dp[200][200];
int main()
{
	memset(dp,MAX,sizeof dp);
	int n,m;
	scanf("%d%d",&n,&m);
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&p[i][j]);
		}
	}
	dp[x][y]=0;
	for(int j=y+1;j<=m;j++)
		dp[x][j]=dp[x][j-1]+p[x][j];
	for(int i=x+1;i<=n;i++)
		dp[i][y]=dp[i-1][y]+p[i][y];
	for(int i=x+1;i<=n;i++){
		for(int j=y+1;j<=m;j++){
			if(i==x&&j==y);
			else
			dp[i][j]=p[i][j]+min(dp[i][j-1],dp[i-1][j]);
		}
	}
	if(n==x&&m==y)
		cout<<"Y 0";
	else if(p[x][y]-dp[n][m]>=0)
		cout<<"Y "<<p[x][y]-dp[n][m];
	else
		cout<<"N";
}
