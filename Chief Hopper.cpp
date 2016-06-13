/* The Key to Solving This Problem Is finding out The Minimum Energy Required To Jump Over One
Building Without Ending Up With Negative Energy
The Minimum energy Required to Jump Successfully over a Builduing Of height H is 
Energy >= (H/2); i.e. ceil(H/2); 
For eg: If H=5, H/2=2.5, Hence E=3 */

#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int v[1000000];
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    
    float z;
    int E=0;
    for(i=n-1;i>=0;i--)
    {
        z= (E+v[i])/2.0;
        E=ceil(z);
    }
    cout<<E;
    return 0;
}
