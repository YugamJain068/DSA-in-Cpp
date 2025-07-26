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
bool solve(unordered_map<int,list<int>>& adj, int n) {
    // finding indegree
    vector<int> indegree(n + 1, 0); // initialize with 0
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;
    // pushing 0 indegree nodes to q
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0; // Initialize cnt to count visited nodes
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        // increment in count
        cnt++;
        // neighbour indegree update
        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    return !(cnt == n);
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
    if(solve(adj,n)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}