#include<bits/stdc++.h>
using namespace std;
int dp[2018][2018];
int fun(int h,int a,int cnt,int turn)
{
	if(h<=0||a<=0)
		return cnt;
	if(dp[h][a]!=-1)
		return dp[h][a];
	if(turn)
	return	dp[h][a]=fun(h+3,a+2,cnt+1,!turn);
	else
	return dp[h][a]=max(fun(h-5,a-10,cnt+1,!turn),fun(h-20,a+5,cnt+1,!turn));
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h,a;
		cin>>h>>a;
		memset(dp,-1,sizeof dp);
		/*int cnt=0;
		int tn=0;
		while(1)
		{
			if(tn)
			{
				if(h>20&&a<=10)
				h-=20,a+=5,cnt++;
				else if(h>5&&a>10)
				h-=5,a-=10,cnt++;
				else
				break;
			}
			else
			{
			if(h>0&&a>0)
			{
			h+=3,a+=2;
			if(h>0&&a>0)
			cnt++;
			}
		}
			tn=(1^tn);
		}
		cout<<cnt<<"\n";*/
		cout<<fun(h,a,-1,1)<<"\n";
	}
}
