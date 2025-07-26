#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool solve(int n,int arr[],int target,int index,vector<vector<int>>&dp){
    //BASE CASE
    if(index>=n){
        return false;
    }
    if(target<0){
        return false;
    }
    if(target==0){
        return true;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    int inc=solve(n,arr,target-arr[index],index+1,dp);
    int exc=solve(n,arr,target-0,index+1,dp);
    return dp[index][target]=inc or exc;
}
int main()
{
    int n;
    cout<<"write size of array: ";
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%2!=0){
        cout<<"no"<<endl;
    }
    else{
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        if(solve(n,arr,target,0,dp)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}