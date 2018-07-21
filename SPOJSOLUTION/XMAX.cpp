#include<bits/stdc++.h>
using namespace std;
vector<long long> group[100];
#define ull unsigned long long
int len(ull n)
{
	int cnt=0;
	while(n)
	{
		cnt++;
		n>>=1;
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	ull a[n+1];
	for(int i=0;i<n;i++)
	{
		ull x;
		cin>>x;
		group[len(x)].push_back(x);
	}	
	ull ans=0;
	int in=0;
	ull dp[200];
	for(int i=64;i>0;i--)
	{
		if(group[i].size())
		{
			dp[in++]=group[i][0];
			for(int j=1;j<group[i].size();j++)
			{
				ull tp=group[i][0] ^ group[i][j];
				group[len(tp)].push_back(tp);
			}
		}
	}
	for(int i=0;i<in;i++)
		ans=max(ans,ans ^ dp[i]);
	cout<<ans;
}
