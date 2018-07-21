#include<bits/stdc++.h>
using namespace std;
long long dp[500][500];
long long dp2[500][500];
long long fun2(string s,int i,int j)
{
	//if(dp2[i][j])
	//	return 1LL*dp2[i][j];
	if(i==j)
		return dp2[i][j]=1LL*(s[i-1]-'0');
	if(dp2[i][j]!=0)
		return dp2[i][j];
	dp2[i][j]=0;
	long long mx=(1LL<<62);
	for(int k=i;k<j;k+=2)
	{
		long long lf=fun2(s,i,k);
		long long rt=fun2(s,k+2,j);
		//cout<<i<<" "<<k<<" "<<j<<" "<<lf<<" "<<rt<<endl;
		if(s[k]=='*')
		mx=min(mx,lf*rt);
		else
		mx=min(mx,lf+rt);
	}
	//cout<<"dp "<<i<<" "<<j<<" "<<mx<<endl;
	return dp2[i][j]=mx;
}
long long fun(string s,int i,int j)
{
	if(i>j)
		return 0LL;
	if(dp[i][j])
		return 1LL*dp[i][j];
	if(i==j)
		return dp[i][j]=1LL*(s[i-1]-'0');
	dp[i][j]=0;
	long long mx=-1;
	for(int k=i;k<j;k+=2)
	{
		long long lf=fun(s,i,k);
		long long rt=fun(s,k+2,j);
		if(s[k]=='*')
		mx=max(mx,lf*rt);
		else
		mx=max(mx,lf+rt);
	}
	return dp[i][j]=mx;
}
void solve(string s)
{
	vector<int> num;
	vector<char> op;
	for(int i=0;i<s.length();i++)
	{
		if(i%2)
			op.push_back(s[i]);
		else
			num.push_back(s[i]-'0');
	}
	int n=num.size();
	long long dp[n+5][n+5][2];
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<n+3;j++)
			dp[i][j][0]=0,dp[i][j][1]=numeric_limits<long long>::max();
	}
	for(int i=0;i<=n;i++)
		dp[i][i][1]=dp[i][i][0]=num[i];
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j=i+l-1;
			for(int k=i;k<j;k++)
			{
				long long mx=0;
				long long mn=0;
				if(op[k]=='*')
				{
				dp[i][j][0]=max(dp[i][j][0],dp[i][k][0]*dp[k+1][j][0]);	
				dp[i][j][1]=min(dp[i][j][1],dp[i][k][1]*dp[k+1][j][1]);
				}
				else{
					dp[i][j][0]=max(dp[i][j][0],dp[i][k][0]+dp[k+1][j][0]);	
					dp[i][j][1]=min(dp[i][j][1],dp[i][k][1]+dp[k+1][j][1]);
				}
			}
		}
	}
	cout<<dp[0][n-1][0]<<" "<<dp[0][n-1][1]<<"\n";
}
int main()
{
	int t;
	cin>>t;
	//n=5000;
	while(t--)
	{
		string s;
		cin>>s;
		solve(s);
		//for(int i=0;i<100;i++)
		//	s+=("+1");
		//cout<<fun(s,1,n)<<" "<<fun2(s,1,n)<<"\n";
	}
}
