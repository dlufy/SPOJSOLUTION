#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	arr[0]=0;
	for(int i=1;i<=n;i++)
	{
		long long x;
		scanf("%lld",&x);
		arr[i]=x;
		arr[i]+=arr[i-1];
	}
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		int j;
		if(m+arr[i-1]>arr[1])
		{
			j=upper_bound(arr+1,arr+n+1,m+arr[i-1])-arr-1;
			if(arr[j]>m+arr[i-1])
				j--;
			ans=max(ans,arr[j]-arr[i-1]);
		}
		
	}
	cout<<ans;
}
