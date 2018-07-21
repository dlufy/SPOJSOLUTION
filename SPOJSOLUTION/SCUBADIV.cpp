#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000
int dp[25][85][1030];
int ox,nt,n;
/*int solve(int i, int co, int cn) {
	if(co >= O && cn >= N) return 0; if(i == n) return INF;
	if(co >= O) co = O; if(cn >= N) cn = N;
	if(fl[i][co][cn] == cs) return dp[i][co][cn]; fl[i][co][cn] = cs;
	return dp[i][co][cn] = min(solve(i+1, co, cn), solve(i+1, co + oxi[i], cn + nitro[i]) + w[i]);
}*/
int solve(int i,int O,int N,vector<pair<pair<int,int>,int> > arr)
{
	//cout<<i<<" "<<O<<" "<<N<<endl;
	if(O>=ox&& N>=nt)
		return 0;
	if(i==n)
		return MAX;
	if(O>=ox)
		O=ox;
	if(N>=nt)
		N=nt;
	if(dp[i][O][N]!=-1)
		return dp[i][O][N];
	return dp[i][O][N]=min(solve(i+1,O,N,arr),arr[i].second+solve(i+1,O+arr[i].first.first,N+arr[i].first.second,arr));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		vector<pair<pair<int,int>,int> > arr;
		cin>>ox>>nt;
		memset(dp,-1,sizeof dp);
		cin>>n;
		for(int i=0;i<n;i++){
			int o,n,w;
			scanf("%d%d%d",&o,&n,&w);
			arr.push_back(make_pair(make_pair(o,n),w));
		}
		cout<<solve(0,0,0,arr)<<"\n";
	}
}
