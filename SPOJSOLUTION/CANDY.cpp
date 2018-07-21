#include<bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
			break;
		int arr[n+5];
		int sum=0;
		for(int i=0;i<n;i++)
			cin>>arr[i],sum+=arr[i];
		if(sum%n)
			cout<<"-1\n";
		else{
			sum/=n;
			int ans=0;
			for(int i=0;i<n;i++)
				if(arr[i]>sum)
					ans+=(abs(arr[i]-sum));
			cout<<ans<<"\n";
		}
	}
}
