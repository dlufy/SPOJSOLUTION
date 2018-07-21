    #include<bits/stdc++.h>
    using namespace std;
    int arr[105][105];
    int fun(int n,int m)
    {
    	int dp[101][101];
    	for(int i=0;i<m;i++)
    	dp[0][i]=arr[0][i];
    	for(int i=1;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			int a=0;
    			dp[i][j]=arr[i][j];
    			if(j!=0)
    			a=max(a,dp[i-1][j-1]);
    			a=max(a,dp[i-1][j]);
    			if(j!=m-1)
    			a=max(a,dp[i-1][j+1]);
    			dp[i][j]+=a;
    		}
    	}
    	int ans=0;
    	for(int i=0;i<m;i++)
    	ans=max(ans,dp[n-1][i]);
    	return ans;
    }
    int main()
    {
    	int t;
    	scanf("%d",&t);
    	while(t--)
    	{
    		int n,m;
    		scanf("%d%d",&n,&m);
    		for(int i=0;i<n;i++)
    		{
    			for(int j=0;j<m;j++)
    			cin>>arr[i][j];
    		}
    		cout<<fun(n,m)<<endl;
    	}
    } 
