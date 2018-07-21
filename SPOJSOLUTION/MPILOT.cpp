#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000000000000000 
ll dp[10010][10010];
ll x[10010],y[10010];
int n;
ll solve()
{
	ll d[n+5][n+5];
	memset(d,MAX,sizeof d);
	for(int i=1;i<n;i++)
		d[0][i]=y[0];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j>0&&j<i)
				d[i][j]=min(d[i-1][j+1]+x[i],d[i-1][j-1]+y[i]);
			else if(j==0)
				d[i][j]=(d[i-1][j+1]+x[i]);
			else 
				d[i][j]=d[i-1][j-1]+y[i];
				cout<<d[i][j]<<" ";
		}
		cout<<"\n";
	}
	return d[n-1][0];
}
ll solve2(int i,int j)
{
    if(j<0)
        return MAX;
    else if(i==0)
        return y[0];
    if(dp[i][j]!=0)
        return dp[i][j];
    dp[i][j] = min(solve2(i-1,j+1)+x[i],solve2(i-1,j-1)+y[i]);
    return dp[i][j];
}
 
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
    }
    dp[0][0] = y[0];
    cout<<solve2(n-1,0)<<endl;
    //cout<<solve2(n-2,0)<<endl;
    cout<<solve2(n-3,0)<<endl;
    //cout<<solve2(n-4,0)<<endl;
    cout<<solve2(1,0)<<endl;
    //cout<<solve();
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	cout<<dp[i][j]<<" ";
    	cout<<endl;
	}
}
