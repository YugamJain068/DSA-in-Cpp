//not getting output

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
        void dfs(int &timer, vector<int> &disc, vector<int> &low, int parent, unordered_map<int, bool> &vis, int node, vector<vector<int>> &ans) {
    vis[node] = true;
    disc[node] = low[node] = timer;

    for (auto nbr : adj[node]) {
        if (nbr == parent)
            continue;
        if (!vis[nbr]) {
            dfs(timer, disc, low, node, vis, nbr, ans);
            low[node] = min(low[node], low[nbr]);
            if (low[nbr] > disc[node]) {
                vector<int> result;
                result.push_back(node);
                result.push_back(nbr);
                ans.push_back(result);
            }
        } else {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}
        vector<vector<int>>findbridge(int n){
            int timer=0;
            vector<int>disc(n);
            vector<int>low(n);
            int parent=-1;
            unordered_map<int,bool>vis;
            for(int i=0;i<n;i++){
                disc[i]=-1;
                low[i]=-1;
                vis[i]=false;
            }
            vector<vector<int>>ans;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                dfs(timer,disc,low,parent,vis,i,ans);
                }
            }
            return ans;
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
    vector<vector<int>>ans;
    ans=g.findbridge(n);
    for (const auto& innerVec : ans) {
        // Iterate over each element in the inner vector
        for (int num : innerVec) {
            cout << num << " ";
        }
        cout << endl; // Print newline after each inner vector
    }
}