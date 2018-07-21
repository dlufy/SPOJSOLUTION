#include<bits/stdc++.h>
using namespace std;
long long brute(int a,int b){
	long long ans=0;
	for(int i=a;i<=b;i++)
	{
		int z=i;
		while(z>0){
			ans+=(z%10);
			z/=10;
		}
	}
	return ans;
}
int main()
{
	while(1){
		int a,b;
	scanf("%d%d",&a,&b);
	if(a==-1&&b==-1)
		break;
	cout<<brute(a,b)<<"\n";
}
}
