#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int cnt=0;
		int f=0;
		for(int i=s.size()-1;i>=0;i--)
			{
				if(s[i]=='.')
				{
					f=1;
					break;
				}
				else
					cnt++;
			}
		int num=0;
		for(int i=0;i<s.size();i++)
			num=s[i]!='.'?num*10+(s[i]-'0'):num;
		int deno=1;
		if(f)
			deno=pow(10,cnt);
		cout<<fr/__gcd(deno,num)<<"\n";
	}
}
