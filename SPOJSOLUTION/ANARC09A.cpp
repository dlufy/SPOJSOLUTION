#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int t=0;
	while(cin>>s&&s[0]!='-')
	{
		t++;
		int n=s.length();
		int mmb=0;
		int mm=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='{')
			mmb++;
			else if(mmb>0)
				mmb--;
			else
			mmb++,mm++;
		}
		cout<<t<<". "<<mm+mmb/2<<endl;
	}
}
