#include <bits/stdc++.h>
using namespace std;
int mincost(vector<int> coins,int t,vector<int> &dp){
    //base case
    if(t==0){
        return 0;
    }
    if(t<0){
        return INT_MAX;
    }
    if(dp[t]!=-1){
        return dp[t];
    }
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans=mincost(coins,t-coins[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    dp[t]=mini;
    return dp[t];
}
int main()
{
    vector<int>coins;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        coins.push_back(data);
    }
    int target;
    cout<<"write target: ";
    cin>>target;
    vector<int>dp(target+1,-1);
    int ans=mincost(coins,target,dp);
    cout<<ans;
    return 0;
}