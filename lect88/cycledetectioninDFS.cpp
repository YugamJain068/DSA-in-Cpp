#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class graph{
    public: 
        unordered_map<int,list<int>>adj;
        unordered_map<int,list<int>> addedge(int u,int v,bool direction){
            //direction--->0--->undirected
            //direction--->1--->directed
            //creating an edge from u to v
            adj[u].push_back(v);
            if(direction==0){
                adj[v].push_back(u);
            }
            return adj;
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
};
bool DFS(int node,int parent,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj){
    vis[node]=1;
    for(auto neighbour:adj[node]){
        if(!vis[neighbour]){
            bool cycledetected=DFS(neighbour,node,vis,adj);
            if(cycledetected){
                return true;
            }
        }
        else if(neighbour!=parent){
                return true;
            }
    }
    return false;
}
string solve(int n,int m,unordered_map<int,list<int>>adj){
    unordered_map<int,bool>vis;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bool ans=DFS(i,-1,vis,adj);
            if(ans==1){
                return "yes";
            }
        }   
    }
    return "no";
}
int main()
{
    int n;
    cout<<"enter no. of nodes: ";
    cin>>n;
    int m;
    cout<<"enter no. of edges: ";
    cin>>m;
    graph g;
    unordered_map<int,list<int>>adj;
    //creating graph
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"enter the value of u and v: "<<endl;
        cin>>u>>v;
        //creating an undirected graph so direction--->0
        adj=g.addedge(u,v,0);
    }
    //printing the graph
    g.printadjlist();
    string ans=solve(n,m,adj);
    cout<<ans;
    return 0;
}