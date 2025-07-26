#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&days,vector<int>&cost){
    vector<int>dp(days.size()+1,INT_MAX);
    dp[days.size()]=0;
    
    for(int k=days.size()-1;k>=0;k--){
        //1 day pass
        int opt1=cost[0]+dp[k+1];
        //7 days pass
        int i;
        for(i=k;i<days.size() && days[i]<days[k]+7;i++){}
        int opt2=cost[1]+dp[i];
        //30 days pass
        for(i=k;i<days.size() && days[i]<days[k]+30;i++){}
        int opt3=cost[2]+dp[i];
        dp[k]=min(opt1,min(opt2,opt3));
    }
    return dp[0];
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
    int ans=solve(days,cost);
    cout<<ans;
    return 0;
}