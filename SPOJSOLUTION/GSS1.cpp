#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Tree{
	ll prefix;
	ll suffix;
	ll total;
	ll best;
};
Tree stree[200000];
ll a[100000];
void build(int l,int r,int ti)
{
	if(l==r)
	{
		stree[ti].best=a[l];
		stree[ti].prefix=a[l];
		stree[ti].suffix=a[l];
		stree[ti].total=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,2*ti);
	build(mid+1,r,2*ti+1);
	Tree t1=stree[ti*2];
	Tree t2=stree[2*ti+1];
	stree[ti].total=t1.total+t2.total;
	stree[ti].prefix=max(t1.prefix,t1.total+t2.prefix);
	stree[ti].suffix=max(t2.suffix,t2.total+t1.suffix);
	stree[ti].best=max(t1.best,max(t2.best,t1.suffix+t2.prefix));
}
Tree query(int ql,int qr,int tl,int tr,int ti)
{
	Tree ans;
	// tree node out of range return min
	if(tl>tr||tr<ql||tl>qr)
	{
		ans.best=ans.prefix=ans.suffix=INT_MIN;
		ans.total=0;
		return ans;
	}
	//if interval is in the required range return stree[ti]
	if(tl>=ql&&tr<=qr)
		return stree[ti];
	// partial node in range
	int mid=(tl+tr)/2;
	Tree q1=query(ql,qr,tl,mid,2*ti);
	Tree q2=query(ql,qr,mid+1,tr,2*ti+1);
	ans.total=q1.total+q2.total;
	ans.prefix=max(q1.prefix,q1.total+q2.prefix);
	ans.suffix=max(q2.suffix,q2.total+q1.suffix);
	ans.best=max(q1.suffix+q2.prefix,max(q1.best,q2.best));
	return ans;
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,n,1);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		Tree t=query(x,y,1,n,1);
		cout<<t.best<<"\n";
	}
}
