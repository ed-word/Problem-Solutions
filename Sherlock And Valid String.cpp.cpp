#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;


int main() {  
    
    map<char,int> m; //Used to Store the no. Of times an alphabet appears in the string.
    set<char>s; 
    set<int>x;
    multiset<int>y;
    string st;
    int i,k;
    
    cin>>st;  //enter the string  
    for(i=0;i<st.size();i++)
    {
        s.insert(st[i]);
        if(s.size()!=i+1)  { ++m[st[i]]; } //Indicates that the alphabet already exists in the set and is repeating.
        
        else               {  m[st[i]]=1;} //Setting value to 1 for first occurence of alphabet.        
    }
    
    
    map<char,int>::iterator it;
    for(it=m.begin();it!=m.end();++it)
    {
        x.insert(it->second); //For string aabbccdfg, x={2,1}
        y.insert(it->second); // For the same string y={2,2,2,1,1,1}
    }
    
    
    
    if(x.size()>2) {cout<<"NO"; }  //More than 2 frequencies of alphabets exists.   
    else if(x.size()==1) { cout<<"YES"; } //All alphabets have same frequency
    
    else   //For x.size=2 i.e when the alphabets occur in two frequencies.
           // eg. To Distinguish Between aabbccd(YES) and aabbccdef(NO) which both have frequencies={1,2}
    {
        multiset<int>::iterator f;
        set<int>::iterator its;
        k=0;
        for(its=x.begin();its!=x.end();++its)
        {
            f=y.find(*its);
            y.erase(f);                      
            if(y.find(*its)!=y.end()) k++; //Increments k if there is more than one element with same frequency.
        } 
        
        if(k!=2) cout<<"YES";
        else cout<<"NO";
    }
    
     return 0;
}
