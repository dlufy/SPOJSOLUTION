#include<bits/stdc++.h>
using namespace std;
long long a[100000];
long long col[100000];
long long tmp[100000];
int main()
{
	int n,m;
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				scanf("%lld",&a[j]);
			tmp[0]=a[0];
			tmp[1]=max(a[0],a[1]);
			for(int j=2;j<m;j++)
				tmp[j]=max(tmp[j-1],a[j]+tmp[j-2]);
			col[i]=tmp[m-1];
		}
		tmp[0]=col[0];
		tmp[1]=max(col[1],col[0]);
		for(int i=2;i<n;i++)
			tmp[i]=max(tmp[i-1],col[i]+tmp[i-2]);
		cout<<tmp[n-1]<<"\n";
	}
}
