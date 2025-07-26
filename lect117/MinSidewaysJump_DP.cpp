#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&obs,int currlane,int currpos,vector<vector<int>>&dp){
    int n=obs.size();
    //BASE CASE
    if(currpos==n-1){
        return 0;
    }
    if(dp[currlane][currpos]!=-1){
        return dp[currlane][currpos];
    }
    if(obs[currpos+1]!=currlane){
        return solve(obs,currlane,currpos+1,dp);
    }
    else{
        //SIDEWAYS JUMP
        int ans=INT_MAX;
        for(int i=1;i<=3;i++){
            if(currlane!=i && obs[currpos]!=i){
                ans=min(ans,1+solve(obs,i,currpos,dp));
            } 
        }
        dp[currlane][currpos]=ans;
        return dp[currlane][currpos];
    }
}
int main()
{
    int n;
    cout<<"wirte size of obstacles vector: ";
    cin>>n;
    vector<int>obs(n);
    for(int i=0;i<n;i++){
        cin>>obs[i];
    }
    vector<vector<int>>dp(4,vector<int>(obs.size(),-1));
    int ans=solve(obs,2,0,dp);
    cout<<ans;
    return 0;
}