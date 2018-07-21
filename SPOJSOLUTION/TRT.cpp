#include<bits/stdc++.h>
using namespace std;
long long val[100000];
long long dp[2018][2018];
long long fun(int start,int end,int n)
{
	if(start>end)
	return 0;
	if(dp[start][end]!=0)
		return dp[start][end];
	int y=n-(end-start);
	long long startselected=(y*1LL)*(val[start])+fun(start+1,end,n);
	long long endselected=(y*1LL)*(val[end])+fun(start,end-1,n);
	return dp[start][end]=max(startselected,endselected);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>val[i];
	cout<<fun(0,n-1,n);
}
