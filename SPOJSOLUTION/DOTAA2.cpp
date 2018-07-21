#include<bits/stdc++.h>
using namespace std;
struct cmp{
	bool operator ()(pair<pair<int,pair<int,int> >,string> p1,pair<pair<int,pair<int,int> >,string> p2){
		if(p1.first.first!=p2.first.first)
			return p1.first.first>p2.first.first;
		else if(p1.first.second.first!=p2.first.second.first)
			return p1.first.second.first>p2.first.second.first;
		else if(p1.first.second.second!=p2.first.second.second)
			return p1.first.second.second<p2.first.second.second;
		else
			return p1.second<p2.second;
	}
};
vector<pair<pair<int,pair<int,int> >,string> > arr;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int f,se,t;
		cin>>f>>se>>t;
		arr.push_back(make_pair(make_pair(f,make_pair(se,t)),s));
	}
	sort(arr.begin(),arr.end(),cmp());
	for(int i=0;i<n;i++)
		cout<<arr[i].second<<"\n";
}
