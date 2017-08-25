#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,q,i;
    int query,x,y,lastAnswer = 0;
    int index, *seq_ptr;
    cin >> n >> q;
    
    int *seq[n], seq_len[n]={0};
    for(i=0;i<n;i++)
        seq[i] = (int*) malloc(1 * sizeof(int));
    
    
    for(i=0;i<q;i++)
    {
        cin >> query >> x >> y;
        index = (x^lastAnswer)%n;
        seq_ptr = seq[index];
        
        if(query==1)
        {
            seq_ptr[seq_len[index]] = y;
            seq_len[index]++;
        }
        else
        {
            lastAnswer = seq_ptr[ y %seq_len[index] ];
            cout << lastAnswer << "\n";
        }
    }
    
    return 0;
}
