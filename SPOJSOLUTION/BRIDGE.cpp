#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		pair<int,int>a[n];
		int dp[n+4];
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			a[i].first=x;
			dp[i]=1;
		}
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			a[i].second=x;
		}
		sort(a,a+n);
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[j].first<=a[i].first&&a[j].second<=a[i].second)
					dp[i]=max(dp[i],1+dp[j]);
			}
			ans=max(ans,dp[i]);
		}
		cout<<ans<<"\n";
	}
}
