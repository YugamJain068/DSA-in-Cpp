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
        void printadjlist(){
            for(auto i:adj){
                cout<<i.first<<"--->";
                for(auto j:i.second){
                    cout<<"("<<j.first<<","<<j.second<<") , ";
                }
                cout<<endl;
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

    int s;
    cout<<"write source: ";
    cin>>s;
    
    //creating distance vector with infinite value initially
    vector<int>dist(n);
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[s]=0;//initializing with zero

    //cretaion of set on basis(node distance,top node)
    set<pair<int,int>>st;
    st.insert(make_pair(0,s));

    while(!st.empty()){
        auto top=*(st.begin());
        int nodedist=top.first;
        int topnode=top.second;
        //remove top node
        st.erase(st.begin());
        //traverse on neighbour
        for(auto neighbour:adj[topnode]){
            if(nodedist+neighbour.second<dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                //if record found erase it
                if(record!=st.end()){
                    st.erase(record);
                }
                //distance update
                dist[neighbour.first]=nodedist+neighbour.second;
                //push record in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    cout<<"answer: "<<endl;
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" , ";
    }
    return 0;
}