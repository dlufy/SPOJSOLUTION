#include<bits/stdc++.h>
using namespace std;
int vis[200];
int main()
{
	int n=1;
	while(n<302)
	{
		//cin>>n;
		n++;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		int n1=n;
		int d=3;
		int i=1;
		while(n1>1)
		{
			n1--;
			int t=0;
			while(1)
			{
				if(vis[i]==0)
					t++;
				if(t==d)
				{
					vis[i]=1;
					break;
				}
				i++;
				if(i>n)
					i=1;
			}
		}
		cout<<"n "<<n<<" ";
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				cout<<"winner is "<<i<<endl;
			}
		}
	}
}
