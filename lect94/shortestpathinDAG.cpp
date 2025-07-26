#include <bits/stdc++.h>
using namespace std;
class graph{
    public: 
        unordered_map<int,list<pair<int,int>>>adj;
        unordered_map<int,list<pair<int,int>>>addedge(int u,int v,int w){   //directed acyclic graph
            pair<int,int> p =make_pair(v,w);
            adj[u].push_back(p);
            return adj;
        }
        void printadjlist(){
            for(auto i:adj){
                cout<<i.first<<"--->";
                for(auto j:i.second){
                    cout<<"("<<j.first<<","<<j.second<<") , ";
                }
                cout<<endl;
            }
        }
        void DFS(int node,unordered_map<int,bool>&vis,stack<int>&st){
            vis[node]=true;
            for(auto neighbour:adj[node]){
                if(!vis[neighbour.first]){
                    DFS(neighbour.first,vis,st);
                }
            }
            st.push(node);
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
    unordered_map<int,list<pair<int,int>>>adj;
    //creating graph
    for(int i=0;i<m;i++){
        int u,v,w;
        cout<<"enter the value of u and v and weight: "<<endl;
        cin>>u>>v>>w;
        //creating an undirected graph so direction--->0
        adj=g.addedge(u,v,w);
    }
    //printing the graph
    g.printadjlist();
    unordered_map<int,bool>vis;
    stack<int>st;
    //topological sort
    for(int i=0;i<n;i++){
        if(!vis[i]){
            g.DFS(i,vis,st);
        }
    }
    int s;
    cout<<"write source: ";
    cin>>s;
    
    //creating distance vector
    vector<int>dist(n);
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[s]=0;//initializing with zero

    //updating the stack to get answer
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(dist[top]!=INT_MAX){
            for(auto i:adj[top]){
                if(dist[top]+i.second<dist[i.first]){
                    dist[i.first]=dist[top]+i.second;
                }
            }
        }
    }
    cout<<"answer: "<<endl;
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" , ";
    }
    return 0;
}