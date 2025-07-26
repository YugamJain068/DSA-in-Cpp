#include <bits/stdc++.h>
using namespace std;
int mincost(vector<int> coins,int t){
   vector<int>dp(t+1,INT_MAX);
   dp[0]=0;
    for(int i=1;i<=t;i++){
        for(int j=0;j<coins.size();j++){
            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }

        }
    }   
    if(dp[t]==INT_MAX){
        return -1;
    }
    return dp[t];
}
int main()
{
    vector<int>coins;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        coins.push_back(data);
    }
    int target;
    cout<<"write target: ";
    cin>>target;
    int ans=mincost(coins,target);
    cout<<ans;
    return 0;
}