#include<bits/stdc++.h>
using namespace std;
char maze[105][105];
int n,m,k,x,y;
int row[]={1,0,-1,0};
int col[]={0,1,0,-1};
int vis[105][105];
int dfs(int xi,int yj,int st)
{
	if(vis[xi][yj])
	{
		if(x==xi&&y==yj&&st>=k)
		 return 1;
		return 0;
	}
	vis[xi][yj]=1;
	for(int i=0;i<4;i++)
	{
		int a=xi+row[i];
		int b=yj+col[i];
		if(a>0&&a<=n&&b>0&&b<=m&&maze[a][b]=='.')
		{
			if(dfs(a,b,st+1))
			return 1;
		}
	}
	vis[xi][yj]=0;
	return 0;
}
int main()
{

	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	scanf("%d%d",&x,&y);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cin>>maze[i][j];
	}
	if(dfs(x,y,0))
	cout<<"YES";
	else
	cout<<"NO";
}
