#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
set<string> print(string a,string b,int m,int n)
{
	set<string> s;
	if(n=0||m==0)
	{
		s.insert("");
		return s;
	}
	if(a[m-1]==b[n-1])
	{
		set<string> t=print(a,b,m-1,n-1);
		for (string ss : t)
		s.insert(ss+a[m-1]);
	}
	else
	{
		if(dp[m-1][n]>=dp[m][n-1])
			s=print(a,b,m-1,n);
		if(dp[m][n-1]>=dp[m-1][n])
		{
			set<string> t=print(a,b,m,n-1);
			s.insert(t.begin(),t.end());
		}
	}
	return s;
}
void fun(string a,string b)
{
	int n=a.length();
	int m=b.length();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	/*cout<<"|| |";
	for(int j=0;j<m;j++)
	cout<<b[j]<<" ";
	cout<<endl;
	for(int i=0;i<=n;i++)
	{
		if(i)
		cout<<a[i-1]<<" ";
		else
		cout<<"||";
		for(int j=0;j<=m;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	set<string> s=print(a,b,n,m);
	for(string ss:s)
	cout<<ss<<"\n";
}
int main() {
	
	// your code here
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		fun(a,b);
	}
	return 0;
}
