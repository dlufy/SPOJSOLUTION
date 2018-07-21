#include<bits/stdc++.h>
using namespace std;
void fun(string s1,string s2)
{
	int n=s1.length();
	int m=s2.length();
	int dp[n+10][m+10];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int i=n;
	int j=m;
	string lcs;
	while(i>0&&j>0)
	{
		if(s1[i-1]==s2[j-1])
			lcs+=s1[i-1],i--,j--;
		else if(dp[i-1][j]>dp[i][j-1])
			i--;
		else
			j--;
	}
	//cout<<lcs<<endl;
	string ans;
	i=n-1,j=m-1;
	int len=dp[n][m];
	int l=0;
	while(i>=0||j>=0)
	{
		if(l<len){
			while(i>=0&&s1[i]!=lcs[l])
				ans+=s1[i--];
			while(j>=0&&s2[j]!=lcs[l])
				ans+=s2[j--];
			i--;
			j--;
			ans+=lcs[l++];	
		}
		else{
		while(i>=0)
			ans+=s1[i--];
		while(j>=0)
			ans+=s2[j--];
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
}
int main()
{
	string a,b;
	while(cin>>a&&a.length())
	{
		cin>>b;
		fun(a,b);
	}
}
