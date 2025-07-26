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
        vector<pair<pair<int,int>,int>>MST(int n){
            //creation of all needed data structure
            vector<int>key(n+1);
            vector<bool>mst(n+1);
            vector<int>parent(n+1);
            //initializing all vectors
            for(int i=0;i<=n;i++){
                key[i]=INT_MAX;
                mst[i]=false;
                parent[i]=-1;
            }
             //starting the algo
                key[1]=0;
                parent[1]=-1;
                for(int i=1;i<n;i++){
                    int mini=INT_MAX;
                    int u;
                    //finding min key vali index
                    for(int j=1;j<=n;j++){
                        if(mst[j]==false && key[j]<mini){
                            u=j;
                            mini=key[j];
                        }
                    }
                    //marking min node as true
                    mst[u]=true;
                    //check its adj
                    for(auto it:adj[u]){
                        int v=it.first;
                        int w=it.second;
                        if(mst[v]==false && w<key[v]){
                            key[v]=w;
                            parent[v]=u;
                        }
                    }
                }
                vector<pair<pair<int,int>,int>>ans;
                for(int i=2;i<=n;i++){
                    ans.push_back(make_pair(make_pair(parent[i],i),key[i]));
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
    unordered_map<int,list<pair<int,int>>>adj;
    //creating graph
    for(int i=0;i<m;i++){
        int u,v,w;
        cout<<"enter the value of u and v and weight: "<<endl;
        cin>>u>>v>>w;
        //creating an undirected graph so direction--->0
        adj=g.addedge(u,v,w);
    }
    vector<pair<pair<int,int>,int>>ans;
    ans=g.MST(n);
    for (int i = 0; i < ans.size(); ++i) {
        cout << "(" << ans[i].first.first << ", " << ans[i].first.second << "), " << ans[i].second << endl;
    }
    return 0;
}