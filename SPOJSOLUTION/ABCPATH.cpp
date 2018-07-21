#include<bits/stdc++.h>
using namespace std;
int ml;
int n,m;
int vis[100][100];
int xx[8]={0,0,1,-1,1,-1,1,-1};
int yy[8]={-1,1,0,0,1,-1,-1,1};
bool ck(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m)
		return false;
	return true;
}
void dfs(string mz[],int x,int y,int len)
{
	//cout<<x<<" "<<y<<" "<<len<<endl;
	ml=max(ml,len);
	vis[x][y]=1;
	for(int i=0;i<8;i++)
	{
		int nx=x+xx[i];
		int ny=y+yy[i];
		if(ck(nx,ny)&&vis[nx][ny]==0&&mz[nx][ny]==char(1+mz[x][y]))
			dfs(mz,nx,ny,len+1);
	}
}
int main(){
	int tn=0;
	while(1){
		tn++;
		cin>>n>>m;
	if(n==0&&m==0)
		break;
	string mz[n+4];
	for(int i=0;i<n;i++)
		cin>>mz[i];
		ml=0;
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mz[i][j]=='A')
				dfs(mz,i,j,1);
		}
	}
	cout<<"Case "<<tn<<": "<<ml<<endl;
	}
	return 0;
}
