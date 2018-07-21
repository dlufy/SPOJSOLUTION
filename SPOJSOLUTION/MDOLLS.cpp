#include<bits/stdc++.h>
using namespace std;
struct cmp{
	bool operator()(pair<int,int> p1,pair<int,int> p2){
		if(p1.first!=p2.first)
			return p1.first<p2.first;
		else
			return p2.second<p1.second;
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<pair<int,int> > v;
		for(int i=0;i<n;i++)
		{
			int l,w;
			scanf("%d%d",&l,&w);
			v.push_back(make_pair(l,w));
		}
		sort(v.begin(),v.end(),cmp());
		//for(int i=0;i<n;i++)
		//cout<<v[i].first<<" "<<v[i].second<<endl;
		vector<pair<int,int> > bucket;
		bucket.push_back(v[n-1]);
		for(int i=n-2;i>=0;i--)
		{
			int l=0;
			int r=bucket.size()-1;
			//cout<<"r "<<r<<"\n";
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(bucket[mid].first==v[i].first||bucket[mid].second<=v[i].second)
					l=mid+1;
				else
					r=mid-1;
			}
			if(l==bucket.size())
				bucket.push_back(v[i]);
			else
				bucket[l].first=v[i].first,bucket[l].second=v[i].second;
		}
		cout<<bucket.size()<<"\n";
	}
}
