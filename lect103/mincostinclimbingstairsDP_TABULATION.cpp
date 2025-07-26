#include <bits/stdc++.h>
using namespace std;
int mincost(vector<int> cost,int n){
    //step 1 --->creating a dp array
    vector<int>dp(n+1);
    //step 2 --->base case analysis
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
int main()
{
    vector<int>cost;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        cost.push_back(data);
    }
    int ans=mincost(cost,size);
    cout<<ans;
    return 0;
}