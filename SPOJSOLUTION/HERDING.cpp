#include<bits/stdc++.h>
using namespace std;
string gd[1010];
int vis[1010][1010];
int n,m,ck=1,ans;
void dfs(int x,int y)
{
	if(!vis[x][y])
	vis[x][y]=ck;
	else
	{
		if(vis[x][y]==ck)
		return;
		else
		{
			ans--;
			return;
		}
	}
	if(gd[x][y]=='S')
	dfs(x+1,y);
	if(gd[x][y]=='E')
	dfs(x,y+1);
	if(gd[x][y]=='N')
	dfs(x-1,y);
	if(gd[x][y]=='W')
	dfs(x,y-1);
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>gd[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j])
			ans++,dfs(i,j),ck++;
		}
	}
	cout<<ans;
}
