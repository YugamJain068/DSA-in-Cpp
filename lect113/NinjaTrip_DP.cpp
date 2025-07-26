#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&days,vector<int>&cost,int index,vector<int>&dp){
    //BASE CASE
    if(index>=days.size()){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    //1 day pass
    int opt1=cost[0]+solve(days,cost,index+1,dp);
    //7 days pass
    int i;
    for(i=index;i<days.size() && days[i]<days[index]+7;i++){}
    int opt2=cost[1]+solve(days,cost,i,dp);
    //30 days pass
    for(i=index;i<days.size() && days[i]<days[index]+30;i++){}
    int opt3=cost[2]+solve(days,cost,i,dp);

    dp[index]=min(opt1,min(opt2,opt3));
    return dp[index];
}
int main()
{
    int size;
    cout<<"write size of days array: ";
    cin>>size;
    vector<int>days(size);
    vector<int>cost(3);
    for(int i=0;i<days.size();i++){
        cin>>days[i];
    }
    for(int i=0;i<cost.size();i++){
        cin>>cost[i];
    }
    vector<int>dp(days.size(),-1);
    int index=0;
    int ans=solve(days,cost,index,dp);
    cout<<ans;
    return 0;
}