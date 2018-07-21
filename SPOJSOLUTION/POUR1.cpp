/*
///////////HINT://////////////////////
 fill A, empty it into B. whenever A becomes empty fill it back, whenever B becomes full empty it.
 each individual move is a step
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(a==0)
	return b;
	return gcd(b%a,a);
}
int cnt(int a,int b,int c)
{
int step=1,a1=a,b1=0,l=0;
while(a1!=c&&b1!=c)
{
	l=min(a1,b-b1);
	b1+=l;
	a1-=l;
	step++;
	if(a1==c||b1==c)
	break;
	if(!a1)
	step++,a1=a;
	if(b1==b)
	step++,b1=0;
}	
return step;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
	int a,b,c;
	cin>>a>>b>>c;
	if((c>max(a,b))||(c%gcd(a,b)))
	cout<<-1<<endl;
	else
	cout<<min(cnt(a,b,c),cnt(b,a,c))<<endl;
	}
}

