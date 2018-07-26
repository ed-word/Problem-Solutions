#include <iostream>
#define endl "\n"

using namespace std;

bool visit[52][252];
long long table[52][252];
int m;

long long find(int i, int n, int c[])
{
    if(n<0)
    	return 0;
    if(n==0)
    	return 1;
    if(i > m)
    	return 0;
    if(visit[i][n] == false)
    {
        table[i][n] = find(i, n - c[i], c) + find(i+1, n, c);
        visit[i][n] = true;
    }
    return table[i][n];
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n>>m;
    int c[m+1];

    for(int i=1;i<=m;i++)
        cin>>c[i];
    
    cout<<find(1, n, c)<<endl;
    return 0;
}
