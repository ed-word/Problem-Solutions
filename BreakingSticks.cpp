#include <bits/stdc++.h>
using namespace std;
int pnum[] = {2,3,5,7};

unordered_map<long long,long long> m;

long long factor(long long num)
{
    if(num == 1)
        return 1;
    
    if ( m.find(num) != m.end() )
        return m[num];
    
    long long sroot = sqrt(num);
    long long i;
    for(i=0;pnum[i]<7 && pnum[i]<=sroot;i++)
    {
        if(num%pnum[i] == 0)
        {
            m.insert(pair<long long,long long>(num,num/pnum[i]));
            return num/pnum[i];
        }
    }
    if(pnum[i]==7)
    {
        for(i=7;i<=sroot;i++)
        {
            if(num%i == 0)
            {
                m.insert(pair<long long,long long>(num,num/i));
                return num/i;
            }
        }
        return 1;
    }
    else
    {
        return 1;
    }
    return 1;
}

long long longestSequence(vector <long long> a)
{
    long long sum = 0;
    auto it = a.begin();
    for(;it!=a.end();++it)
    {
        sum += *it;
        
        long long x = *it;
        while(x!=1)
        {
            x = factor(x);
            sum += x;
        }
    }
    return sum;
}

int main() {
    
    m.insert(pair<long long,long long>(1,1));
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    long long result = longestSequence(a);
    cout << result << endl;
    return 0;
}
