#include<bits/stdc++.h>
using namespace std;
vector<int > graph[500001];
int vis[100001];
int vis1[100001];
int flag;
void dfs(int cur,int par)
{
    vis[cur]=1;
    int i;
    for(i=0;i<graph[cur].size();i++)
    {
        if(vis[graph[cur][i]]==1&&graph[cur][i]!=par)
            flag=1;
        if(!vis[graph[cur][i]])
        dfs(graph[cur][i],cur);

    }
}
int main()
{
    int n,m,x,y,i,cnt=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
          }
          for(i=1;i<=n;i++)
          {
              if(!vis[i])
              {
                 dfs(i,i);
                 cnt++;
              }
          }
          if(flag==0&&cnt==1&&m==(n-1))
            cout<<"YES\n";
          else
            cout<<"NO\n";
}

