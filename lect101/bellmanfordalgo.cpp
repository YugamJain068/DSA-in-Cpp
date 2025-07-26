#include <bits/stdc++.h>
using namespace std;
class graph{
    public: 
        unordered_map<int,list<pair<int,int>>>adj;
        void addedge(int u,int v,int w){   
            pair<int,int> p =make_pair(v,w);
            adj[u].push_back(p);                        //DIRECTED GRAPH
        }
        vector<int> bellmanford(int src,int n) {
            vector<int> dist(n + 1, 1e9); // Vector size should be n+1
            dist[src] = 0;
            for (int i = 1; i <= n - 1; i++) { // Loop from 1 to n-1
                for (int j = 1; j <= n; j++) { // Loop from 1 to n
                    for (auto k : adj[j]) {
                        int a = j;
                        int b = k.first;
                        int c = k.second;
                        if (dist[a] != 1e9 && ((dist[a] + c) < dist[b])) {
                            dist[b] = dist[a] + c;
                        }
                    }
                }   
            }
            // Check for negative cycles while updating distances
            for (int j = 1; j <= n; j++) { // Loop from 1 to n
                for (auto k : adj[j]) {
                    int a = j;
                    int b = k.first;
                    int c = k.second;
                    if (dist[a] != 1e9 && ((dist[a] + c) < dist[b])) {
                        cout<<"-ve cycle detected"<<endl;
                        vector<int>null(n,-1);
                        return null; // Negative cycle detected
                    }
                }
            }
            return dist;
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
    for(int i=1;i<=m;i++){
        int u,v,w;
        cout<<"enter the value of u and v and weight: "<<endl;
        cin>>u>>v>>w;
        //creating an directed graph so direction--->1
        g.addedge(u,v,w);
    }

    cout<<"enter the source: ";
    int src;
    cin>>src;
    vector<int>ans;
    ans=g.bellmanford(src,n);
    for(auto i:ans){
        cout<<i<<" ";
    }
}