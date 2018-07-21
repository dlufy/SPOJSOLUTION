#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000
pair<int,int> arr[200000];
long long dp[200000];
int n;
struct cmp{
	bool operator() (const pair<int,int> &p1,const pair<int,int> &p2){
		return p1.first<p2.first;
	}
};
int find(pair<int,int>  arr[],int l,int r,int s)
{
	//to find index of activity having start_time >=s
	while(l<r)
	{
		int mid=(l+r)/2;
		if(arr[mid].first<s)
			l=mid+1;
		else
			r=mid;
	}
	for(int i=l;i<=r;i++)
		if(arr[i].first>=s)
			return i;
	return n;
}
int main()
{

	int s,e;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		for(int i=0;i<n;i++)
		{
			dp[i]=0;
			scanf("%d %d",&s,&e);
			arr[i].first=s;
			arr[i].second=e;
		}
	sort(arr,arr+n,cmp());
	dp[n-1]=1;
	dp[n]=0;
	for(int i=n-2;i>=0;i--)
	{
		int next=find(arr,i,n-1,arr[i].second);
		dp[i]=(1+dp[i+1]%MOD+dp[next]%MOD)%MOD;
	}
	cout<<setfill('0')<<setw(8)<<dp[0]<<endl;
}
return 0;
}
