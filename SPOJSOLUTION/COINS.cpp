#include<bits/stdc++.h>
using namespace std;
map<int,long long> dp;
long long fun(int n)
{
	if(n==0)
	return 0;
	if(dp[n]!=0)
	return dp[n];
	long long int ans1=fun(n/2)+fun(n/3)+fun(n/4);
	if(ans1>n)
	dp[n]=ans1;
	else
	dp[n]=n;
	return dp[n];
}
int main()
{
int n;
while(scanf("%d",&n)==1)
cout<<fun(n)<<endl;
}
