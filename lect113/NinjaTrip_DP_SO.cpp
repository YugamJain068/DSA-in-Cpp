#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&days,vector<int>&cost){
    int ans=0;
    queue<pair<int,int>>monthly;
    queue<pair<int,int>>weekly;
    for(int day:days){
        while(!monthly.empty() && monthly.front().first+30<=day){
            monthly.pop();
        }
        while(!weekly.empty() && weekly.front().first+7<=day){
            weekly.pop();
        }
        weekly.push(make_pair(day,ans+cost[1]));
        monthly.push(make_pair(day,ans+cost[2]));
        ans=min(ans+cost[0],min(monthly.front().second,weekly.front().second));
    }
    return ans;
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