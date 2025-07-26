#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&a,int curr,int prev,vector<vector<int>>dp){
    int n=a.size();
    //BASE CASE
    if(curr==n){
        return 0;
    }
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
    //include
    int inc=0;
    if(prev==-1 || a[curr]>a[prev]){
        inc=1+solve(a,curr+1,curr,dp);
    }
    //not include
    int exc=0+solve(a,curr+1,prev,dp);
    dp[curr][prev+1]=max(inc,exc);          //prev+1--->because -1 index will not be valid
    return dp[curr][prev+1];
}
int main()
{
    int n;
    cout<<"write size of satisfaction vector: ";
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    int ans=solve(a,0,-1,dp);
    cout<<ans;
    return 0;
}