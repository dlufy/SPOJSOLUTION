#include<bits/stdc++.h>
using namespace std;
string s;
int l;
int dp[500][500];
int fun(int pos,int psum)
{
	//cout<<"position and prev sum"<<pos<<" "<<psum<<"\n";
	if(pos==l)
		return 1;
	if(dp[pos][psum]!=-1)
		return dp[pos][psum];
	dp[pos][psum]=0;
	for(int i=pos,tsum=0;i<l;i++)
	{
		tsum+=int(s[i]-'0');
		if(tsum>=psum)
			dp[pos][psum]+=fun(i+1,tsum);
	}
	return dp[pos][psum];
}
int main()
{
	int t=1;
	while(1)
	{
		cin>>s;
		if(s[0]=='b')
		break;
		l=s.length();
		memset(dp,-1,sizeof dp);
		//cout<<dp[1][5]<<dp[5][8]<<"\n";
		cout<<t++<<". "<<fun(0,0)<<"\n";
	}
}
