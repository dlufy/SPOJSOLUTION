#include<bits/stdc++.h>
using namespace std;
long long arr[300000];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	for(int i=0;i<q;i++)
	{
		long long x;
		scanf("%lld",&x);
		int l=0;
		int r=n-1;
		int t=0;
		while(t<19&&l<r)
		{
			t++;
			int mid=(l+r)>>1;
			if(arr[mid]<x)
				l=mid+1;
			else
				r=mid;
		}
		int f=0;
		for(int j=l;j<=r;j++)
			if(arr[j]==x)
			printf("%d\n",j),f=1;
		if(!f)
		printf("-1\n");
	}
}
