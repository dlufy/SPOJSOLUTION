#include<bits/stdc++.h>
using namespace std;
struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
};
int fun(int x[],int y[],int n,int m)
{
	int dp[n+5][m+5];
	dp[0][0]=0;//for n=1 we need not to cut chocolate
		for(int i=1;i<=n;i++)
			dp[i][0]=dp[i-1][0]+x[i-1];
		for(int j=1;j<=m;j++)
			dp[0][j]=dp[0][j-1]+y[j-1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int vcut=dp[i-1][j]+x[i-1]*(j+1);
				int hcut=dp[i][j-1]+y[j-1]*(i+1);
				dp[i][j]=min(vcut,hcut);
			}
		}
	return dp[n][m];
}
int fun2(int x[],int y[],int n,int m)
{
	int ans=0;
	int i=0;
	int j=0;
	int v=1,h=1;
	while(i<n&&j<m)
	{
		if(x[i]>y[j])
		{
			ans+=v*x[i];
			i++;
			h++;
		}
		else{
			ans+=h*y[j++];
			v++;
		}
	}
	int sum=0;
	while(i<n){
		sum+=x[i++];
	}
	ans+=sum*v;
	sum=0;
	while(j<m){
		sum+=y[j++];
	}
	ans+=sum*h;
	return ans;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int x[n+5];
		int y[m+5];
		for(int i=0;i<n-1;i++)
			cin>>x[i];
		for(int i=0;i<m-1;i++)
			cin>>y[i];
		sort(x,x+n-1,cmp());
		sort(y,y+m-1,cmp());
		n--;
		m--;
		//cout<<fun(x,y,n,m);
		cout<<fun2(x,y,n+1,m+1)<<"\n";
	}
}
