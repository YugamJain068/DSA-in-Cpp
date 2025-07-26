#include <bits/stdc++.h>
using namespace std;
int maxrod(int  n,int x,int y,int z,vector<int>dp){
    //base case
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int a=maxrod(n-x,x,y,z,dp)+1;
    int b=maxrod(n-y,x,y,z,dp)+1;
    int c=maxrod(n-z,x,y,z,dp)+1;
    int d=max(a,b);
    dp[n]=max(d,c);
    return dp[n];
}
int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    vector<int>dp(n+1,-1);
    int ans=maxrod(n,x,y,z,dp);
    if(ans<0){
        cout<<"0";
    }
    else{
    cout<<ans;
    }
    return 0;
}