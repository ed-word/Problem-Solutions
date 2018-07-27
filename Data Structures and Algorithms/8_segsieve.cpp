#include <iostream>
#include <math.h>
#define endl "\n"
#define lint long long
using namespace std;


void sieve(int prime[])
{
	int i,j;
	for(i=2; (i*i)<=100000; i++)
	{
		if(prime[i-1]==0)
		{
			for(j=2*i;j<100000;j+=i)
				prime[j-1] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int prime[10000000] = {0};
	prime[0] = 1;
	sieve(prime);

	int T,t;
	cin >> T;

	for(t=0;t<T;t++)
	{
		lint a,b;
		int i;
		cin >> a >> b;

		for(i=a;i<=b;i++)
			if(prime[i-1]==0)
				cout << i << endl;
		cout << endl;
	}
	return 0;
}