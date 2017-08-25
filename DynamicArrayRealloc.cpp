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
    int index, *seq_ptr, len;
    cin >> n >> q;
    
    int *seq[n], seq_len[n]={0};
    for(i=0;i<n;i++)
        seq[i] = (int*) malloc(1 * sizeof(int));
    
    
    for(i=0;i<q;i++)
    {
        cin >> query >> x >> y;
        index = (x^lastAnswer)%n;
        seq_ptr = seq[index];
        len = seq_len[index];
        
        if(query==1)
        {
            seq_ptr[len] = y;
            seq_len[index]++;
            seq[index] = (int*) realloc(seq[index], (len+2)*sizeof(int));
        }
        else
        {
            lastAnswer = seq_ptr[ y %len ];
            cout << lastAnswer << "\n";
        }
    }
    
    return 0;
}
