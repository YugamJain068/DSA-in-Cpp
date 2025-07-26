#include <bits/stdc++.h>
using namespace std;
class graph{
    public: 
        unordered_map<int,list<int>>adj;
        void addedge(int u,int v,bool direction){
            //direction--->0--->undirected
            //direction--->1--->directed
            //creating an edge from u to v
            adj[u].push_back(v);
            if(direction==0){
                adj[v].push_back(u);
            }
        }
        void printadjlist(){
            for(auto i:adj){
                cout<<i.first<<"--->";
                for(auto j:i.second){
                    cout<<j<<" , ";
                }
                cout<<endl;
            }
        }
        void dfs(int node,int par,vector<int>&disc,vector<int>&low,unordered_map<int,bool>&vis,vector<int>&ap,int n,int &timer){
            vis[node]=true;
            low[node]=disc[node]=timer++;
            int child=0;
            for(auto nbr:adj[node]){
                if(nbr==par){
                    continue;
                }
                if(!vis[nbr]){
                    dfs(nbr,node,disc,low,vis,ap,n,timer);
                    low[node]=min(low[node],low[nbr]);
                    //check for ap
                    if(low[nbr]>=disc[node] && par!=-1){
                        ap[node]=1;
                    }
                    child++;
                }
                else{
                    //back edge
                    low[node]=min(low[node],disc[nbr]);
                }
            }
            if(par==-1 && child>1){
                ap[node]=1;
            }
        }
};
int main()
{
    int n;
    cout<<"enter no. of nodes: ";
    cin>>n;
    int m;
    cout<<"enter no. of edges: ";
    cin>>m;
    graph g;
    //creating graph
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"enter the value of u and v: "<<endl;
        cin>>u>>v;
        //creating an undirected graph so direction--->0
        g.addedge(u,v,0);
    }
    //printing the graph
    g.printadjlist();

    //creating the required data structures
    int timer=0;
    vector<int>disc(n);
    vector<int>low(n);
    unordered_map<int,bool>vis;
    vector<int>ap(n,0);
    //iniitalizing
    for(int i=0;i<n;i++){
        disc[i]=-1;
        low[i]=-1;
    }
    //dfs
    for(int i=0;i<n;i++){
        if(!vis[i]){
            g.dfs(i,-1,disc,low,vis,ap,n,timer);
        }
    }
    //printing articulation points
    cout<<"articulation points are as follows: ";
    for(int i=0;i<n;i++){
        if(ap[i]!=0){
            cout<<i<<" ";
        }
    }cout<<endl;
}