#include<bits/stdc++.h>
using namespace std;
int dp[2000000];
int main()
{
	int k,l,m;
	cin>>k>>l>>m;
	int mv=0;
	int g[1000];
	for(int i=0;i<m;i++)
	cin>>g[i],mv=max(mv,g[i]);
	dp[1]=1;
	for(int i=2;i<=mv;i++)
	{
		if(!dp[i-1])
			dp[i]=1;
		else if(i-k>=0&&!dp[i-k])
			dp[i]=1;
		else if(i-l>=0&&!dp[i-l])
			dp[i]=1;
	}
	for(int i=0;i<m;i++)
		if(dp[g[i]])
			cout<<"A";
		else
		cout<<"B";
}
