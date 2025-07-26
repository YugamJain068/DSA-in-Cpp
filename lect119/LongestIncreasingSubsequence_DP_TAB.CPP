#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&a){
    int n=a.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int inc=0;
            if(prev==-1 || a[curr]>a[prev]){
                inc=1+dp[curr+1][curr+1];           //curr+1--->because -1 index will not be valid as prev is changed to current
            }
            //not include
            int exc=0+dp[curr+1][prev+1];           //prev+1--->because -1 index will not be valid
            dp[curr][prev+1]=max(inc,exc);          //prev+1--->because -1 index will not be valid
        }
    }
    return dp[0][0];        //-1+1=0
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
    int ans=solve(a);
    cout<<ans;
    return 0;
}