#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[2000];
ll g[2000];
ll h[2000];
int main(){
	int t;
	scanf("%d",&t);
	g[0]=1LL;
	g[1]=2LL;
	h[0]=1LL;
	h[1]=1LL;
	dp[0]=1LL;
	dp[1]=1LL;
	for(int i=2;i<1001;i++){
		dp[i]=dp[i-1]+dp[i-2]+2*g[i-2]+h[i-2];
		g[i]=dp[i]+g[i-1];
		h[i]=h[i-2]+dp[i];
	}
	int tn=1;
	while(t--){
		int n;
		cin>>n;
		cout<<tn++<<" "<<dp[n]<<"\n";
	}
}
