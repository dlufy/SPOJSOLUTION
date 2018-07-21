#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > gr[2000];
int vis[2000];
int color[2000];
int ans=100000000;
int dis1[2000];
int dis2[2000];
int n,m;
void dfs()
{
	w+=color[u];
	b+=(!color[u]);
	if(u==n)
	{
		if(abs(w-b)<=1)
		ans=min(ans,wt);
		return;
	}
	vis[u]=1;
	for(int i=0;i<gr[u].size();i++)
	{
		if(!vis[gr[u][i].first])
		{
			dfs(gr[u][i].first,wt+gr[u][i].second,w,b);
		}
	}
	vis[u]=0;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		gr[x].push_back(make_pair(y,w));
		gr[y].push_back(make_pair(x,w));
	}
	for(int i=1;i<=n;i++)
		cin>>color[i];
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<gr[1].size();i++)
	{
		vis[1]=1;
		dfs(gr[1][i].first,gr[1][i].second,color[1],(!color[1]));
	}
	cout<<ans<<endl;
}
