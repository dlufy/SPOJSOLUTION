#include<bits/stdc++.h>
using namespace std;
long long  arr[10005];
long long dp[10005];
int main()
{
	int t,tn=0;
	cin>>t;
	while(t--)
	{
		tn++;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		dp[0]=arr[0];
		dp[1]=max(arr[0],arr[1]);
		for(int i=2;i<n;i++)
			dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
		cout<<"Case "<<tn<<": "<<dp[n-1]<<"\n";
	}
}
