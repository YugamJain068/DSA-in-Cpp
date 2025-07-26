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
void DFS(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis,int node,vector<int>&comp){
    comp.push_back(node);
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            DFS(adj,vis,i,comp);
        }
    }
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
    unordered_map<int,bool>vis;
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<int>comp;
            DFS(adj,vis,i,comp);
            ans.push_back(comp);
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
        }
    cout<<endl;
    }
    return 0;
}