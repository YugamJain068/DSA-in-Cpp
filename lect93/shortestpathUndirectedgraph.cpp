#include <bits/stdc++.h>
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
vector<int> solve(unordered_map<int,list<int>>& adj, int n,int s, int d) {
    unordered_map<int , bool>vis;
    unordered_map<int , int>par;
    queue<int>q;
    q.push(s);
    par[s]=-1;
    vis[s]=true;
    //cretaing parent map for graph
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(!vis[i]){
                vis[i]=true;
                par[i]=front;
                q.push(i);
            }
        }
    }

    //finding shortest path
    vector<int>ans;
    int currentnode=d;
    ans.push_back(d);
    while(currentnode!=s){
        currentnode=par[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    int s,d;
    cout<<"write source and destination: ";
    cin>>s>>d;
    vector<int>ans;
    ans=solve(adj,n,s,d);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}