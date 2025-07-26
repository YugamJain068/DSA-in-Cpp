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
        //topological sort function
        void dfs(int node,stack<int>&st,unordered_map<int,bool>&vis,int n){
            vis[node]=true;
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    dfs(nbr,st,vis,n);
                }
            }  
            st.push(node);  
        }
        //transposing function
        void trans(unordered_map<int,list<int>>&transpose,int n,unordered_map<int,bool>&vis){
            for(int i=0;i<n;i++){
                vis[i]=0;
                for(auto nbr:adj[i]){
                    transpose[nbr].push_back(i);
                }
            }
        }
        //new DFS function
        void newdfs(int node,unordered_map<int,list<int>>&transpose,unordered_map<int,bool>&vis){
            vis[node]=true;
            for(auto nbr:transpose[node]){
                if(!vis[nbr]){
                    newdfs(nbr,transpose,vis);
                }
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
        //creating an directed graph so direction--->1
        g.addedge(u,v,1);
    }
    //printing the graph
    g.printadjlist();

    //step 1 --->topological sort
    stack<int>st;
    unordered_map<int,bool>vis;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            g.dfs(i,st,vis,n);
        }
    }
    //step 2 --->trasnposing the graph
    unordered_map<int,list<int>>transpose;
    g.trans(transpose,n,vis);
    //step 3 --->dfs call using above ordering
    int count=0;        //going to be answer
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!vis[top]){
            count++;
            g.newdfs(top,transpose,vis);
        }
    }
    cout<<"no. of SSC in given graph are: "<<count<<endl;
    return 0;
}