#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int e,f;
		cin>>e>>f;
		int n;
		cin>>n;
		vector<pair<int,int> > coin(n+5);
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
		coin[i].first=y;
		coin[i].second=x;
		}
		int dp[f+10];
		dp[0]=0;
		for(int i=1;i<=f;i++)
		{
			dp[i]=MAX;
			for(int j=0;j<n;j++)
			{
				if(coin[j].first<=i)
					dp[i]=min(dp[i],coin[j].second+dp[i-coin[j].first]);
			}
		}
		if(dp[f-e]!=MAX)
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[f-e]<<".\n";
		else
			cout<<"This is impossible.\n";
		
	}
}
