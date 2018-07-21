#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100000];
ll arr1[100000];
ll arr2[100000];
ll arr3[100000];
ll fun(int n,int m)
{
	ll ans=0;
	int i=0;
	int j=0;
	int pi=-1;
	int pj=-1;
	while(i<n&&j<m)
	{
		if(arr[i]==arr1[j])
		{
			//cout<<" i and j "<<arr[i]<<" "<<i<<" "<<j<<" ";	
			if(pi!=-1&&pj!=-1)
				ans+=(max(arr2[i]-arr2[pi],arr3[j]-arr3[pj]));
			else
				ans+=(max(arr2[i],arr3[j]));
			//cout<<ans<<endl;
			pi=i;
			pj=j;
			i++;
			j++;
		}
		else if(arr[i]>arr1[j])
			j++;
		else
			i++;
	}
	if(pi!=-1&&pj!=-1)
		ans+=(max(arr2[n-1]-arr2[pi],arr3[m-1]-arr3[pj]));
	else
	ans+=max(arr2[n-1],arr3[m-1]);
	return ans;
}
int main()
{
	int n,m;
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>m;
		for(int i=0;i<m;i++)
			cin>>arr1[i];
		arr2[0]=arr[0];
		arr3[0]=arr1[0];
		for(int i=1;i<n;i++)
		arr2[i]=arr[i]+arr2[i-1];
		for(int i=1;i<m;i++)
		arr3[i]=arr1[i]+arr3[i-1];
	cout<<fun(n,m)<<endl;
	}
	return 0;
}
