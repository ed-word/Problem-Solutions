#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

int main()
{
	int n,q,x;
	int i,j,k;
	
	unordered_map <int, list<int> > m;
	
	cin >> n >> q;
	
	int up[n];
	int down[n];
	for(i=1;i<=n;i++)
	{
		cin >> x;
		for(j=1;j<=x;j++)
		{
			cin >> k;
			m[i].push_back(k);
		}
	}
	for(i=1;i<=n;i++)
	{
		cout << "Cycle: " << i << endl;
		auto it = m[i].begin();
		for(;it!=m[i].end();++it)
			cout << *it << " ";
		cout<<endl;
	}
	
	int v1,v2,w;
	for(i=1;i<=n;i++)
	{
		cin >> v1 >> v2 >> w;
	}
	
	return 0;
}
