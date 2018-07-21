#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000
int fun(string x,string y,int k)
{
	int n=x.length();
	int m=y.length();
	int dp[n+4][m+5];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0)
				dp[i][j]=k*j;
			else if(j==0)
				dp[i][j]=k*i;
			else if(x[i-1]==y[j-1])
				dp[i][j]=dp[i-1][j-1];
			else{
				dp[i][j]=min(min(k+dp[i][j-1],k+dp[i-1][j]),abs(x[i-1]-y[j-1])+dp[i-1][j-1]);
			}
		}
	}
	return dp[n][m];
}
int main()
{
	string x,y;
	cin>>x>>y;
	int cr;
	cin>>cr;
	cout<<fun(x,y,cr)<<endl;
}
