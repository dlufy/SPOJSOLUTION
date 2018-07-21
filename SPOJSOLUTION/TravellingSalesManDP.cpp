#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000
int dp[1<<20][20];
int n;
int cost[20][20];
int tsp(int mask,int pos)
{
	if(mask==((1<<n)-1)){
		return cost[pos][0];
	}
	if(dp[mask][pos]!=-1)
		return dp[mask][pos];
		
	int ans=MAX;
	
	for(int city=0;city<n;city++)
	{
		if((mask&(1<<city))==0)
		{
			int tans=cost[pos][city]+tsp(mask^(1<<city),city);
			ans=min(ans,tans);
		}
	}
	return dp[mask][pos]=ans;
}
int main()
{
	for(int i=0;i<(1<<20);i++)
		for(int j=0;j<20;j++)
			dp[i][j]=-1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>cost[i][j];
	}
	cout<<"minimum cost to visit cities or min cost hamiltonian cycle "<<tsp(1,0);
}
