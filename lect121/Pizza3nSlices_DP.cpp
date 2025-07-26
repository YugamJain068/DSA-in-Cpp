#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&pizza,int index,int endindex,int n,vector<vector<int>>&dp){
    //BASE CASE
    if(n==0 || index>endindex){
        return 0;
    }
    if(dp[index][n]!=-1){
        return dp[index][n];
    }
    int inc=pizza[index]+solve(pizza,index+2,endindex,n-1,dp);
    int exc=0+solve(pizza,index+1,endindex,n,dp);
    dp[index][n]=max(inc,exc);
    return dp[index][n];
}
int main()
{
    int k;
    cout<<"write the total no. of slices in pizza: ";
    cin>>k;
    vector<int>pizza(k);
    for(int i=0;i<pizza.size();i++){
        cin>>pizza[i];
    }
    //if 1st index element is included, then last index element will be excluded
    vector<vector<int>>dp1(k,vector<int>(k,-1));
    int ans_1=solve(pizza,0,k-2,k/3,dp1);
    //if 1st index element is excluded, then last index element will be included
    vector<vector<int>>dp2(k,vector<int>(k,-1)); 
    int ans_2=solve(pizza,1,k-1,k/3,dp2);
    int ans=max(ans_1,ans_2);
    cout<<ans;
    return 0;
}