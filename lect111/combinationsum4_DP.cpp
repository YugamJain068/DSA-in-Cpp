#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr,int tar,vector<int>&dp){
    //base case
    if(tar<0){
        return 0;
    }
    if(tar==0){
        return 1;
    }
    if(dp[tar]!=-1){
        return dp[tar];
    }
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans+=solve(arr,tar-arr[i],dp);
    }
    dp[tar]=ans;
    return dp[tar];
}
int main()
{
    vector<int>arr;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    int tar;
    cin>>tar;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    vector<int>dp(tar+1,-1);
    int ans=solve(arr,tar,dp);
    cout<<ans;
    return 0;
}