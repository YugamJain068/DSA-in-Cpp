//not completed

#include <bits/stdc++.h>
using namespace std;
class graph{
    public: 
        unordered_map<int,list<pair<int,int>>>adj;
        unordered_map<int,list<pair<int,int>>>addedge(int u,int v,int w){   
            pair<int,int> p =make_pair(v,w);
            pair<int,int> p2 =make_pair(u,w);
            adj[u].push_back(p);                        //UNDIRECTED GRAPH
            adj[v].push_back(p2);
            return adj;
        }
        void makeset( vector<int>&rank,vector<int>&parent,int n){
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=0;
            }
        }
        int findparent(vector<int>&parent,int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node]=findparent(parent,parent[node]);
        }
        void unionset(int u,int v,vector<int>&parent,vector<int>rank){
            u=findparent(parent,u);
            v=findparent(parent,v);
            if(rank[u]<rank[v]){
                parent[u]=v;
            }
            else if(rank[u]>rank[v]){
                parent[v]=u;
            }
            else{
                parent[v]=u;
                rank[u]++;
            }
        }
        int MST(int n){
            vector<int>rank(n);
            vector<int>parent(n);
            makeset(parent,rank,n);
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
}