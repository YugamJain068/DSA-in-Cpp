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
void BFS(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis,vector<int>&ans,int node){
    queue<int>q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto i:adj[frontnode]){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
            }
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
        adj=g.addedge(u,v,1);
    }
    //printing the graph
    g.printadjlist();
    unordered_map<int,bool>vis;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            BFS(adj,vis,ans,i);
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}