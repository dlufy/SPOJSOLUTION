#include<bits/stdc++.h>
using namespace std;
int vis[100];
int a[100];
int dp[20][200];
int dpsolve(int n,int k)
{
	if(n==0)
		return 0;
	if(k==0)
		return 1;
	if(dp[n][k]!=-1)
		return dp[n][k];
	dp[n][k]=0;
	for(int i=0;i<n&&k-i>=0;i++)
		dp[n][k]+=dpsolve(n-1,k-i);
	return dp[n][k];
}
int n,k,ans;
void fun(int i)
{
	if(i==n)
	{
		int inv=0;
		for(int l=0;l<n;l++)
		{
			for(int j=l+1;j<n;j++)
				if(a[l]>a[j])
					inv++;
		}
		if(inv==k)
			ans++;
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(!vis[j])
		{
			vis[j]=1;
			a[i]=j;
			fun(i+1);
			vis[j]=0;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(dp,-1,sizeof dp);
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			a[0]=i;
			//fun(1);
			vis[i]=0;
		}
		dpsolve(n,k);
		printf("%d\n",dp[n][k]);
	}
	
}
