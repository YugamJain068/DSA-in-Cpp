#include <bits/stdc++.h>
using namespace std;
int mincost(vector<int> cost,int n,vector<int> &dp){
    //base case
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    //step 3 --->returning saved value of dp[n] if any present
    if(dp[n]!=-1){
        return dp[n];
    }
    //step 2 --->returning dp[n]
    dp[n]=cost[n]+min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
    return dp[n];
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
    //step 1 --->creating a dp array
    vector<int>dp(size+1,-1);
    //we will start from stair having less cost out of 0th and 1st stair
    int ans=min(mincost(cost,size-1,dp),mincost(cost,size-2,dp));
    cout<<ans;
    return 0;
}