#include <bits/stdc++.h>
using namespace std;
long long int arr[2000000];
int main() {
	
	int n,m,w;
	int a,b,q;
	scanf("%d%d%d",&n,&m,&w);
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		arr[a]+=1;
		arr[b+1]-=1;
	}
	for(int i=1;i<w;i++)
	arr[i]+=arr[i-1];
	for(int i=0;i<m;i++)
	{
		scanf("%d",&q);
		cout<<arr[q]<<endl;
	}
	return 0;
}
