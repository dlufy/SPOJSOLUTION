//here center of honeycomb is shifted to n,8,8 to avoid negative coordinates
// here 8 is used because only 14 steps are allowed and to come back origin we can only walk 7 steps away
//from origin
//base case when it is at origin at 0,8,8 number of ways are 1.
//then there is only left is to make solution using k,i,j
//any six sides 
#include<iostream>
using namespace std;
int xx[6]={1,-1,0,0,-1,1};
int yy[6]={0,0,1,-1,-1,1};
int dp[15][18][18];
int pp()
{
	dp[0][8][8]=1;
	for(int k=1;k<=14;k++)
	{
		for(int i=1;i<20;i++)
		{
			for(int j=1;j<20;j++)
			{
				dp[k][i][j]=0;
				for(int in=0;in<6;in++)
					dp[k][i][j]+=dp[k-1][i+xx[in]][j+yy[in]];
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	pp();
	while(t--){
	int n;
	cin>>n;
	cout<<dp[n][8][8]<<"\n";
	//cout <<cw(0,0,0,0,0,n)<<"\n";
}
}
