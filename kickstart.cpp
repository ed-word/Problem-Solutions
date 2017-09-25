#include "iostream"
#include "vector"
#include "set"
#include <math.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,m;
	cin >>t;
	for(m=1;m<=t;m++)
	{	
		int n,i,x,first,last;
		vector <int> v;
		set <int> s;
		
		cin >> n;
		for(i=1;i<=n;i++)
		{
			cin >> x;
			v.push_back(x);
			s.insert(x);
		}
		
		while(n>2)
		{
			x = floor((n-1)/2);
			first = *(s.begin());
			last = *(--s.end());
			if(v[x]!=first || v[x]!=last)
			{
				cout << "Case "<<"#"<<m<<": NO";
				goto L;
			}
			if(v[x]==first)
			{
				s.erase(s.begin());
				v.erase(v.begin()+x);
			}
			else
			{
				s.erase(--s.end());
				v.erase(v.begin()+x);
			}
			n = v.size();
		}
		cout << "Case "<<"#"<<m<<": YES";
		L: cout<<endl;
	}
	return 0;
}
