#include <iostream>
#include <map>
using namespace std;

int main(){
    bool c;
    int t,i,j,k,n,L,l,R,r,x;     //R,L:Rows&Columns Of Grid G. r,l:Of PatternGrid g
    string G,g;                  // G:Grid(bigger)  g:pattern grid
    map<int,string> M,m;
    map<int,string>::iterator it;
    string::size_type f,y;
    y=0;
    cin >> t;            //Test cases
    
    for(i=0;i<t;i++)
    {
        cin>>R>>L;            //Taking Input Row-wise (One Row At a time)
        for(j=1;j<=R;j++)
        {
            cin>>G;
            M[j]=G;
        }
        
        cin>>r>>l;
        for(j=1;j<=r;j++)
        {
            cin>>g;
            m[j]=g;
        }
        
        
        
        c=false;
        for(j=1;j<=R-r+1;j++)
        {
             l: if(c==true)  {
                                j=x;   G=M[j]; g=m[1];
                                c=false;
                 
                                f=G.find(g,f+1); 
                                if(f!=string::npos) 
                                   { x=j; break;}
                           } 
            
            else {
                              G=M[j]; g=m[1];
                              f=G.find(g); c=0;
                              if(f!=string::npos) { x=j; break;}
                 }
            
           
        }
        
        
        if(j>R-r+1) {cout<<"NO"<<endl; continue;   }
        
        j++;
        for(k=2;k<=r;k++)
        {   
            y=0;
            g=m[k]; G=M[j];
        z:  if(G.find(g,y)==string::npos) { c=true; goto l;  }
            if(G.find(g,y)!=f) { y++;  goto z;    }
            else {  j++;  }
        }
        
        
        cout<<"YES"<<endl;
    }
    return 0;
}
