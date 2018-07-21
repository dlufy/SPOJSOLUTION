#include <iostream>
using namespace std;

int main() {
	
	// your code here
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		long long arr[n+5];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		int ans=0;
		int t=0;
		long long tsum=0;
		long long ans1=0;
		long long ans2=0;
		int i=-1;
		int j=0;
		while(i<n&&j<n)
		{
			while(j<n&&tsum+arr[j]<=m)
				tsum+=arr[j++];
			if(ans1<(j-i-1)||(ans1==(j-i-1)&&ans2>tsum))
			{
				ans2=tsum;
				ans1=j-i-1;
			}
			i++;
			tsum-=arr[i];
		}
		cout<<ans2<<" "<<ans1<<"\n";
	}
	return 0;
}
