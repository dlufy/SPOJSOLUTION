#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1005][1005];
int fun(int arr[],int i,int k,int sum)
{	
if(i>=n)
return 0;
if(dp[i][sum]!=-1)
return dp[i][sum];
dp[i][sum]=0;
if(sum+arr[i]<=k)
return dp[i][sum]=max(arr[i]+fun(arr,i+2,k,sum+arr[i]),fun(arr,i+1,k,sum));
else
return dp[i][sum]=fun(arr,i+1,k,sum);
}
int main()
{
	int t,ki=1;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>n>>k;
		int arr[n+5];
		for(int i=0;i<n;i++)
		cin>>arr[i];
			for(int i=0;i<=n;i++)
			{
				for(int j=0;j<=k;j++)
				dp[i][j]=-1;
			}
			int ans=fun(arr,0,k,0);	
			cout<<"Scenario #"<<ki++<<": "<<ans<<endl;
		
	}
}
