#include<bits/stdc++.h>
using namespace std;
long long stall[200000];
bool check(long long m,long long n,long long c)
{
	long long cow=1;
	long long x=stall[0];
	bool flag=true;
	for(int i=1;cow<=c&&i<n;i++)
	{
		while(i<n&&stall[i]-x<m)
			i++;
			//cout<<"i "<<i<<endl;
		if(i<n)
			cow++;
		x=stall[i];
	}
	return cow>=c;
	
}
long long bs(long long l,long long r,long long n,long long c)
{
	int t=0;
	while(t<35&&l<r)
	{
		t++;
		int m=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<m<<" "<<check(m,n,c)<<endl;
		if(check(m,n,c))
			l=m;
		else
			r=m-1;
	}
	for(long long i=r;i>=l;i--)
	{
		if(check(i,n,c))
		return i;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long n,c;
		cin>>n>>c;
		for(int i=0;i<n;i++)
			cin>>stall[i];
		sort(stall,stall+n);
		cout<<bs(0,1000000000,n,c)<<endl;
		//cout<<check(7,n,c)<<endl;
	}
}
