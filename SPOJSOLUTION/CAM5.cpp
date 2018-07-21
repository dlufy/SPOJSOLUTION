#include<bits/stdc++.h>
using namespace std;

int vis[200000];
void dfs(int v,vector<int> vec[])
{
	vis[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		if(!vis[vec[v][i]])
			dfs(vec[v][i],vec);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,e,a,b;
		cin>>n>>e;
		for(int i=0;i<=n;i++)
			vis[i]=0;
		vector<int> vec[n+10];
		for(int i=0;i<e;i++)
		{
			cin>>a>>b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			ans++,dfs(i,vec);
		}
		cout<<ans<<endl;
	}
}
