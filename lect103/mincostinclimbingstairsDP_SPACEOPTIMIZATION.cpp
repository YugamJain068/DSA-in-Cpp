#include <bits/stdc++.h>
using namespace std;
int mincost(vector<int> cost,int n){
    //using space optimization
    int prev2=cost[0];
    int prev1=cost[1];
    for(int i=2;i<n;i++){
        int curr=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}
int main()
{
    vector<int>cost;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        cost.push_back(data);
    }
    int ans=mincost(cost,size);
    cout<<ans;
    return 0;
}