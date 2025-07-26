#include <bits/stdc++.h>
using namespace std;
int sacksolve(vector<int> &weights,vector<int> &values,int index,int capacity,vector<vector<int>> &dp){
    if(index==0){
        if(weights[0]<=capacity){
            return values[0];
        }
        else{
        return 0;
        }
    }
    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }
    int include=0;
    if(weights[index]<=capacity){
        include=values[index]+sacksolve(weights,values,index-1,capacity-weights[index],dp);
    }
    int exclude=0+sacksolve(weights,values,index-1,capacity,dp);
    dp[index][capacity]=max(include,exclude);
    return dp[index][capacity];
}
int main()
{
    vector<int>weights,values;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    cout<<"write weights: "<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        weights.push_back(data);
    }
    cout<<"write values: "<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        values.push_back(data);
    }
    cout<<"write maxweight: ";
    int maxweight;
    cin>>maxweight;
    vector<vector<int>>dp(size,vector<int>(maxweight+1,-1));
    int ans=sacksolve(weights,values,size-1,maxweight,dp);
    cout<<ans;
    return 0;
}