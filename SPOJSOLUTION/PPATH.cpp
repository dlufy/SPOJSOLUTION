#include<bits/stdc++.h>
using namespace std;
int check[100009];

void sieve()
{
    for(int i=2;i<=100;i++){
            if(!check[i])
    for(int j=i*i;j<=10000;j+=i)
        check[j]=1;

}
}
int conv_num(int a[])
{
    int t=0;
    for(int i=0;i<4;i++)
        t=t*10+a[i];
    return t;
}
void arr(int digit[],int n)
{
   int a=n;
   int i=3;
   while(a)
   {
       digit[i--]=a%10;
       a=a/10;
   }
}

int main()
{
int t;
scanf("%d",&t);
sieve();
while(t--){
int s,e;
int digit[4],dist[10009];
memset(digit,-1,sizeof(digit));
memset(dist,-1,sizeof(dist));
scanf("%d%d",&s,&e);

queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<4;i++){
            arr(digit,u);
    for(int j=0;j<=9;j++)
    {
            digit[i]=j;
        int temp=conv_num(digit);
        if(!check[temp]&&dist[temp]==-1&&temp>=1000)
         {
            dist[temp]=dist[u]+1;
            q.push(temp);
        }
    }
    }
    q.pop();
    }

dist[e]==-1?cout<<"Impossible\n":cout<<dist[e]<<endl;
}
return 0;
}

