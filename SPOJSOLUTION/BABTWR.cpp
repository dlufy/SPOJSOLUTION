#include<bits/stdc++.h>
using namespace std;
struct box{
	int h;
	int w;
	int d;
};
struct cmp{
	bool operator () (struct box b1,struct box b2){
		return (b1.d*b1.w) > (b2.d*b2.w);
	}
};
struct box b[10000];
struct box b2[30000];
int main()
{
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&b[i].h,&b[i].w,&b[i].d);
		for(int i=0,j=0;i<n;i++)
		{
			b2[j].h=b[i].d;
			b2[j].d=max(b[i].h,b[i].w);
			b2[j++].w=min(b[i].h,b[i].w);
			
			b2[j].h=b[i].w;
			b2[j].d=max(b[i].h,b[i].d);
			b2[j++].w=min(b[i].h,b[i].d);
			
			b2[j].h=b[i].h;
			b2[j].d=max(b[i].w,b[i].d);
			b2[j++].w=min(b[i].w,b[i].d);
		}
		n=3*n;
		sort(b2,b2+n,cmp());
		//for(int i=0;i<n;i++)
		//	cout<<b2[i].h<<" "<<b2[i].d<<" "<<b2[i].w<<endl;
		int dp[n+5];
		for(int i=0;i<n;i++)
			dp[i]=b2[i].h;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(b2[j].w>b2[i].w&&b2[j].d>b2[i].d)
					dp[i]=max(dp[i],dp[j]+b2[i].h);
				ans=max(ans,dp[i]);
			}
		}
		cout<<ans<<"\n";
	}
}
