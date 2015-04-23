//Author : swarnaprakash
#include<cstdio>
#include<cassert>
#include<iostream>

using namespace std;

long long fun(int n)
{
	long long wt=5,ans=0;
	
	while(n>0)
	{
		if(n&1)
			ans+=wt;
		n>>=1;
		wt*=5;
	}
	return ans;
}

int main()
{
	int n,t;
	cin>>t;
	assert(t<=200);
	while(t--)
	{
		cin>>n;
		assert(n>=1 && n<=8000);
		long long ans=fun(n);
		
		assert(ans<=((1LL<<31)-1));
		cout<<ans<<endl;
	}
	return 0;
}
