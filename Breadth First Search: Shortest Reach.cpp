#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
#include <map>
#include <queue>
using namespace std; 

class Graph 
{
    map<int, list<int>> adj;   
    bool b[100000]= {false};
    int dist[100000];
    
   public:
   void set(int n)
   {
     for(int i=1;i<=n;i++)
     {
         adj[i].clear();
     }
   }
    
   void unique(int n)
   {
       for(int i=1;i<=n;i++)
     {
           adj[i].unique();
     }
   }
     
   void addEdge(int v, int w)
   {
        adj[v].push_back(w);
   }
   
   void BFSdist(int s, int n)
   {
       int v;
       queue<int> Q;
       b[s]= true;
       dist[s]=0;
       Q.push(s);
       
       while(!Q.empty())
       {
           v = Q.front(); Q.pop();
           auto i = adj[v].begin();
           for(;i!=adj[v].end();++i)
           {
               int w =*i;
               if(b[w]==false)
               {
                   dist[w] = dist[v]+1; 
                   b[w]= true;
                   Q.push(*i);
               }   
           }
       }
       
          for(int i=1;i<=n;++i)
       {
           int x;
          if(i!=s)
         {
               
           if(b[i]==false)
           {
               x = -1;
           }
           else x = dist[i]*6;
               
           cout<<x<<" ";
         }
       }
       
   }
    
};



int main() 
{
    int s;   
  	int t,n,m,v,w;
    
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        Graph g;
        cin>>n; g.set(n);
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>v; cin>>w;
            g.addEdge(v, w);
            g.addEdge(w, v);
        }
        g.unique(n);
        cin>>s;
        g.BFSdist(s,n);
        cout<<endl;

    }
      
     return 0;
}
