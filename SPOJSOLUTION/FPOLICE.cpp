#include<bits/stdc++.h>
using namespace std;
int dist[100][100];
int T[100][100];
int dp[2000][100];
#define MAX 1000000000
int fun(int n,int t)
{
	dp[0][0]=0;
	for(int j=1;j<=n;j++)
		dp[0][j]=MAX;
		int lastT=-1;
	for(int tt=1;tt<=t;tt++){
		for(int i=0;i<n;i++){
			dp[tt][i]=dp[tt-1][i];
			for(int j=0;j<n;j++){
				if(tt>=T[j][i])
					dp[tt][i]=min(dp[tt][i],dp[tt-T[j][i]][j]+dist[j][i]);
			}
		}
		if(dp[tt][n-1]!=dp[tt-1][n-1])
			lastT=tt;
		}
		if(dp[t][n-1]!=MAX)
			cout<<dp[t][n-1]<<" "<<lastT<<"\n";
		else
			printf("-1\n");
}
int main()
{
	int tn;
	scanf("%d",&tn);
	while(tn--){
		int n,t;
		scanf("%d%d",&n,&t);
		if(n==0&&t==0)
			break;
			
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				scanf("%d",&T[i][j]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				scanf("%d",&dist[i][j]);
		}
		fun(n,t);
	}
}
