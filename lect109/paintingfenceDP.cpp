#include <bits/stdc++.h>
using namespace std;
int solve(int n,int k,vector<int>&dp){
   //BASE CASE
   if(n==1){
    return k;
   }
   if(n==2){
    return k+(k*(k-1));
   }
   if(dp[n]!=-1){
    return dp[n];
   }
   dp[n]=(solve(n-2,k,dp)*(k-1))+(solve(n-1,k,dp)*(k-1));
   return dp[n];
}
int main()
{
    vector<int>arr;
    int n,k;
    cout<<"write n & k: ";
    cin>>n>>k;
    vector<int>dp(n+1,-1);
    int ans=solve(n,k,dp);
    cout<<ans;
    return 0;
}