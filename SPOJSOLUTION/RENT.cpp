#include<bits/stdc++.h>
using namespace std;
#define ll long long
int bs(vector<pair<int,pair<int,int> > > a,int k)
{
	int n=a.size();
	int l=0;
	int r=n;
	int t=0;
	while(l<r&&t<30)
	{
		t++;
		int mid=(l+r)>>2;
		if(a[mid].first<k)
			l=mid+1;
		else
		r=mid;
	}
	for(int i=l;i<=r;i++)
	{
		if(a[i].first>=k)
			return i;
	}
	return n;
}
ll fun(vector<pair<int,pair<int,int> > > a)
{
	int n=a.size();
	ll dp[n+16];
	for(int i=0;i<n+2;i++)
		dp[i]=0;
	for(int i=n-1;i>=0;i--)
	{
		dp[i]=max(dp[i+1],a[i].second.second+dp[bs(a,a[i].second.first)]);
	}
	return dp[0];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		vector<pair<int,pair<int,int> > > a;
		ll n;
		cin>>n;
		for(ll i=0;i<n;i++)
		{
			ll s,e,p;
			cin>>s>>e>>p;
			e+=s;
			a.push_back(make_pair(s,make_pair(e,p)));
		}
		sort(a.begin(),a.end());
		cout<<fun(a)<<"\n";
	}
	return 0;
}
