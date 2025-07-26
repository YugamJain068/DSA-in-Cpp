#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&v,int i,int j){
    int n=v.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i+2;j<n;j++){
            int ans=INT_MAX;
            for(int k=i+1;k<j;k++){
                ans=min(ans,v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][n-1];
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
    int ans=solve(v,0,n-1);
    cout<<ans;
    return 0;
}