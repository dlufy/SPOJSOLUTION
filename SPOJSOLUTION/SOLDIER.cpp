#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > gr[10];
int main()
{
	int t,n;
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		int type,p,q;
		cin>>type>>p>>q;
		gr[type].push_back(make_pair(p,q));
	}
	for(int i=1;i<7;i++)
	{
		if(gr[i].size()==0)
		{
			cout<<0;
			return 0;
		}
	}
	int pr=0,qt=0;
	vector<pair<int,pair<int,int> > > sol;
	for(int i=1;i<=6;i++)
	{
		int pp=10000000,qq;
		for(int j=0;j<gr[i].size();j++)
		{
			if(pp>gr[i][j].first)
			{
				pp=gr[i][j].first;
				qq=gr[i][j].second;
			}
		}
		sol.push_back(make_pair(qq,make_pair(pp,i)));
		pr+=pp;
	}
	if(pr>t)
	{
		cout<<0;
	}
	else{
		sort(sol.begin(),sol.end());
		for(int i=0;i<6;i++)
		{
			int tp=sol[i].second.second;
			int cmp=sol[i].second.first;
			int lq=sol[i].first;
			int lp=cmp;
				cmp=(t-pr-lp);
			for(int j=0;j<gr[tp].size();j++)
			{
				if(gr[tp][j].first<=cmp&&gr[tp][j].second>lq)
				{
					lp=gr[tp][j].first;
					lq=gr[tp][j].second;
				}
			}
			pr+=lp;
			sol[i].first=lq;
		}
		int ck=1000000;
		for(int i=0;i<6;i++)
		ck=min(ck,sol[i].first);
		cout<<ck;
	}
}
