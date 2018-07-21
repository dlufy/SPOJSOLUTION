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
			stree[ti].best=stree[ti].prefix=stree[ti].suffix=stree[ti].total=a[l];
			return;
		}
	int mid=(l+r)>>1;
	build(l,mid,2*ti);
	build(mid+1,r,2*ti+1);
	Tree t1=stree[ti*2];
	Tree t2=stree[ti*2+1];
	stree[ti].total=t1.total+t2.total;
	stree[ti].prefix=max(t1.prefix,t1.total+t2.prefix);
	stree[ti].suffix=max(t2.suffix,t2.total+t1.suffix);
	stree[ti].best=max(t1.suffix+t2.prefix,max(t1.best,t2.best));
}
Tree query(int ql,int qr,int tl,int tr,int ti)
{
	Tree t;
	if(tl>tr||tr<ql||tl>qr)
	{
		t.best=t.prefix=t.suffix=INT_MIN;
		t.total=0;
		return t;	
	}
	if(tl>=ql&&tr<=qr)
		return stree[ti];
	int mid=(tl+tr)>>1;
	Tree q1=query(ql,qr,tl,mid,2*ti);
	Tree q2=query(ql,qr,mid+1,tr,2*ti+1);
	t.total=q1.total+q2.total;
	t.prefix=max(q1.prefix,q1.total+q2.prefix);
	t.suffix=max(q2.suffix,q2.total+q1.suffix);
	t.best=max(q1.suffix+q2.prefix,max(q1.best,q2.best));
	return t;
}
void update(int l,int r,int ti,int i,ll x)
{
	if(l>r||i<l||i>r)
		return;
	if(l==r)
	{
		stree[ti].best=stree[ti].prefix=stree[ti].suffix=stree[ti].total=x;
		return;
	}
	int mid=(l+r)>>1;
	update(l,mid,2*ti,i,x);
	update(mid+1,r,2*ti+1,i,x);
	Tree t1=stree[ti*2];
	Tree t2=stree[ti*2+1];
	stree[ti].total=t1.total+t2.total;
	stree[ti].prefix=max(t1.prefix,t1.total+t2.prefix);
	stree[ti].suffix=max(t2.suffix,t2.total+t1.suffix);
	stree[ti].best=max(t1.suffix+t2.prefix,max(t1.best,t2.best));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,n,1);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		ll t,x,y;
		cin>>t>>x>>y;
		if(t)
		{	
			Tree t=query(x,y,1,n,1);
			cout<<t.best<<"\n";
		}
		else
		update(1,n,1,x,y);
	}
}
