#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1)
	{
		string s;
		cin>>s;
		if(s[0]=='0')
		break;
		int l=s.length();
		int dp[10000];
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<=l;i++)
		{
			dp[i]=0;
			int c1=s[i-2]-'0';
			int c2=s[i-1]-'0';
			if(c1==1||(c1==2&&c2<=6))
			dp[i]+=dp[i-2];
			if(c2!=0)
			dp[i]+=dp[i-1];
		}
		cout<<dp[l]<<endl;
	}
	return 0;
}
