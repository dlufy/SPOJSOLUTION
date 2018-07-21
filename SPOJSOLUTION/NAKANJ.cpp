#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000
int xx[8]={2,2,-2,-2,1,1,-1,-1};
int yy[8]={1,-1,1,-1,2,-2,2,-2};
int vis[100][100];
bool check(int x,int y,int n)
{
	if(x<1||y<1||x>n||y>n)
		return false;
	return true;
}
int fun(int sx,int sy,int dx,int dy,int n)
{
	queue<pair<int,int> > q;
	pair<int,int> f;
	q.push(make_pair(sx,sy));
		vis[sx][sy]=1;
		int dp[8][8];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			dp[i][j]=MAX;
	}
		dp[sx][sy]=0;
	while(!q.empty())
	{
		f=q.front();
		q.pop();
		int x=f.first;
		int y=f.second;
		for(int i=0;i<8;i++)
		{
			int nx=x+xx[i];
			int ny=y+yy[i];
			if(check(nx,ny,n)&&dp[nx][ny]>dp[x][y]+(x*nx+y*ny))
			{
				dp[nx][ny]=1+dp[x][y];
				q.push(make_pair(nx,ny));
			}
		}
	}
	return (dp[dx][dy]!=MAX?dp[dx][dy]:-1);
}
int main()
{
	int sx,sy,dx,dy;
	
	int t;
	cin>>t;
	while(t--)
	{
		string x,y;
		cin>>x>>y;
		sx=x[0]-'a'+1;
		sy=x[1]-'0';
		dx=y[0]-'a'+1;
		dy=y[1]-'0';
		//scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
		for(int i=0;i<=8;i++)
		{
			for(int j=0;j<=8;j++)
				vis[i][j]=0;
		}
		if(sx==dx&&sy==dy)
		{
			cout<<"0\n";
			continue;
		}
		cout<<fun(sx,sy,dx,dy,8)<<"\n";
	}
}
