#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&s,int index,int time){
    int n=s.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int index =n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
            int inc=(s[index]*(time+1))+dp[index+1][time+1];
            int exc=0+dp[index+1][time];//dish exclude so no dish make so no time consume
            dp[index][time]=max(inc,exc);
        }
    }
    return dp[0][0];
}
int main()
{
    int n;
    cout<<"write size of satisfaction vector: ";
    cin>>n;
    vector<int>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    //sort the vector
    sort(s.begin(),s.end());
    int ans=solve(s,0,0);
    cout<<ans;
    return 0;
}