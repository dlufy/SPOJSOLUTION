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
		stack<char> st;
		int n=s.length();
		for(int i=0;i<n;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			cout<<s[i];
			else if(s[i]==')')
			{
				while(!st.empty()&&st.top()!='(')
					cout<<st.top(),st.pop();
				if(!st.empty())
					st.pop();
			}
			else
			st.push(s[i]);
		}
		while(!st.empty())
		cout<<st.top(),st.pop();
		cout<<endl;
	}
}
