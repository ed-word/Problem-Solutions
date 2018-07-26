#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <list>
#define endl "\n"
#define loop(i,n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

//finding root of an element.
int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root.
    {
     i = Arr[ i ];
    }
    return i;
}
int unionFunc(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B);  
    Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	/*
	double f = 3.1467890;
	cout.precision(15);
	cout << std::fixed << f << '\n';
	*/
	
	/*
	int t;
	cin >> t;
	while(t--) {
	}
	*/
	map< int,list<int> > lang, person, graph;
	int n, m, i, j, k, u, v, x, flag=0, count=0;
	cin >> n >> m;
	int DSU[n];
	loop(i, n) {
		DSU[i] = i;
		
		cin >> k;
		if(k==0)
			count++;
		loop(j, k) {
			cin >> x;
			lang[x].push_back(i);
			person[i].push_back(x);
		}
	}
	loop(i, n) {
		for(auto iter1 : person[i]) {
			for(auto iter2 : lang[iter1]) {
				if(iter2 != i) {
					graph[i].push_back(iter2);
					unionFunc(DSU, i, iter2);
				}
			}
		}
	}

	cout << "person" << endl;
	loop(i, n) {
		cout << i << ": ";
		for(auto iter : person[i]) {
			cout << iter << " ";
		}
		cout << endl;
	}
	
	cout << "lang" << endl;
	for(auto iter1 : lang) {
		cout << iter1.first << ": ";
		for(auto iter2 : lang[iter1.first]) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	
	cout << "GRAPH" << endl;
	loop(i, n) {
		cout << i << ": ";
		for(auto iter : graph[i]) {
			cout << iter << " ";
		}
		cout << endl;
	}
	
	cout << "DSU" << endl;
	loop(i, n) {
		cout << i << " ";
	}
	cout << endl;


	int components = 0;
	loop(i, n) {
		cout << DSU[i] << " ";
		if(DSU[i] == i)
			components++;
	}
	cout << endl;

	if(count==n)
		cout << components;
	else
		cout << components - 1;
		
	return 0;
}
