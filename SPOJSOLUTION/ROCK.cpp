#include<bits/stdc++.h>
using namespace std;
#define MIN -100000000
int fun(int n,string s)
{
	int dp[n+4][n+5];
	int pr[n+5];
		dp[0][0]=0;
	for(int i=1;i<=n;i++)
		dp[i][i]=(s[i-1]-'0');
	pr[0]=0;
	for(int i=1;i<=n;i++)
		pr[i]=pr[i-1]+(s[i-1]=='1');
	for(int l=2;l<=n;l++){
		for(int i=1;i+l<=n+1;i++){
			int j=i+l-1;
			dp[i][j]=(j-i+1-2*pr[j]+2*pr[i-1])<0?j-i+1:0;
			for(int k=i;k<j;k++){
				//cout<<"ikj l r "<<i<<" "<<k<<" "<<j<<" "<<(k-i+1-2*pr[k]+2*pr[i-1])<<" "<<(j-k-2*pr[j]+2*pr[k])<<endl;
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	return dp[1][n];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		string s;
		scanf("%d",&n);
		cin>>s;
		cout<<fun(n,s)<<"\n";
	}
}
