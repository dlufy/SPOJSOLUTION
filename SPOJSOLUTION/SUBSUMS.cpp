#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back 
typedef vector<ll> vll;
ll arr[40];
vll sbs1;
vll sbs2;
ll ways;
int main()
{
	ll n,A,B;
	cin>>n>>A>>B;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int size=n/2;
	size=(1<<size);
	ll s=0;
	for(int i=0;i<size;i++)
	{
		s=0;
		for(int j=0;j<n/2;j++)
		{
			if(i&(1<<j))
				s+=arr[j];
		}
		sbs1.pb(s);
	}
	sort(sbs1.begin(),sbs1.end());
	int n2=n-(n/2);
	int size2=(1<<n2);
	for(int i=0;i<size2;i++)
	{
		s=0;
		for(int k=0,j=n/2;k<n2;k++,j++)
		{
			if(i&(1<<k))
			s+=arr[j];
		}

		sbs2.pb(s);
	}
	ll ans=0;
	for(int i=0;i<size2;i++)
	{
		vll::iterator lb=lower_bound(sbs1.begin(),sbs1.end(),A-sbs2[i]);
		vll::iterator ub=upper_bound(sbs1.begin(),sbs1.end(),B-sbs2[i]);
		ans+=(ub-lb);
		//cout<<ans<<" "<<i<<endl;
	}
	cout<<ans;
}
