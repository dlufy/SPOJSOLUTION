#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		vector<pair<int,int> > pr;
		vector<int> v;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int s,e;
			cin>>s>>e;
			pr.push_back(make_pair(s,e));
			v.push_back(s);
			v.push_back(e);
		}
		int ans=0;
		for(int i=0;i<v.size();i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++)
			if(pr[j].first<=v[i]&&pr[j].second>=v[i])
				cnt++;
			ans=max(ans,cnt);
		}
		cout<<ans<<"\n";
	}
}
