#include<bits/stdc++.h>
using namespace std;
int dp_knapsack(int cap,vector<pair<int,int> > bag,int k)
{
	int dp[cap+5][k+5];
	for(int i=0;i<cap+3;i++)
	{
		for(int j=0;j<k+4;j++)
			dp[i][j]=0;
	}
	for(int i=1;i<=cap;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(bag[j-1].first<=i)
			{
				dp[i][j]=max(dp[i-bag[j-1].first][j-1]+bag[j-1].second,dp[i][j-1]);
			}
			else
			dp[i][j]=dp[i][j-1];
		}
	}
	return dp[cap][k];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int c,k;
		cin>>c>>k;
		vector<pair<int,int> > bag;
		for(int i=0;i<k;i++)
		{
			int w,v;
			cin>>w>>v;
			bag.push_back(make_pair(w,v));
		}
		cout<<"Hey stupid robber, you can get "<<dp_knapsack(c,bag,k)<<"."<<endl;
	}
}
