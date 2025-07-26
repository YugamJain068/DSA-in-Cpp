#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&s,int index,int time,vector<vector<int>>dp){
    if(index==s.size()){
        return 0;
    }
    if(dp[index][time]!=-1){
        return dp[index][time];
    }
    int inc=(s[index]*(time+1))+solve(s,index+1,time+1,dp);
    int exc=0+solve(s,index+1,time,dp);//dish exclude so no dish make so no time consume
    dp[index][time]=max(inc,exc);
    return dp[index][time];
}
int main()
{
    int n;
    cout<<"write size of satisfaction vector: ";
    cin>>n;
    vector<int>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    //sort the vector
    sort(s.begin(),s.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int ans=solve(s,0,0,dp);
    cout<<ans;
    return 0;
}