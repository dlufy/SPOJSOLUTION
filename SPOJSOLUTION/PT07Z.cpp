#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
vector<int> v[20000];
bool check[MAX]={false};
int total=0;
int dfs(int root)
{
    int m,m1=-1,m2=-1;
    check[root]=1;
    for(int i=0;i<v[root].size();i++)
    {
        if(!check[v[root][i]]){
            m = dfs(v[root][i]);
            if(m>=m1)
            {
                m2= m1;
                m1 = m;
            }
            else if(m>m2)
                m2=m;
        }
    }
    total = max(total , m1+m2+2);
    return (m1 + 1);
}
int main()
{
    int n,a,b;
    cin>>n;
    
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout<<total<<endl;
}
