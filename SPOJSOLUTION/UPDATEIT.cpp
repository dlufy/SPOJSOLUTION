#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,u;
		scanf("%d%d",&n,&u);
		long long arr[n+6];
		for(int i=0;i<=n+1;i++)
			arr[i]=0;
		for(int i=0;i<u;i++)
		{
			int l,r;
			long long val;
			scanf("%d%d%lld",&l,&r,&val);
			arr[l]+=val;
			arr[r+1]-=val;
		}
		for(int i=1;i<=n;i++)
			arr[i]+=arr[i-1];
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			int in;
			scanf("%d",&in);
			printf("%lld\n",arr[in]);
		}
	}
}
