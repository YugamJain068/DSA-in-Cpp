#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp){
    //BASE CASE ----> only 2 vertex given, triangle not possible
    if(i+1==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,v[i]*v[j]*v[k] + solve(v,i,k,dp) + solve(v,k,j,dp));
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    int n;
    cout<<"wirte no. of vertex: ";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int ans=solve(v,0,n-1,dp);
    cout<<ans;
    return 0;
}