#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&obs){
    int n=obs.size()-1;
    vector<vector<int>>dp(4,vector<int>(obs.size(),INT_MAX));
    dp[0][n]=0;
    dp[1][n]=0;
    dp[2][n]=0;
    dp[3][n]=0;
    for(int currpos=n-1;currpos>=0;currpos--){
        for(int currlane=1;currlane<=3;currlane++){
            if(obs[currpos+1]!=currlane){
                dp[currlane][currpos]=dp[currlane][currpos+1];
            }
            else{
                //SIDEWAYS JUMP
                int ans=INT_MAX;
                for(int i=1;i<=3;i++){
                    if(currlane!=i && obs[currpos]!=i){
                        ans=min(ans,1+dp[i][currpos+1]);
                    } 
                }
                dp[currlane][currpos]=ans;
            }
        }
    }
    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
}
int main()
{
    int n;
    cout<<"wirte size of obstacles vector: ";
    cin>>n;
    vector<int>obs(n);
    for(int i=0;i<n;i++){
        cin>>obs[i];
    }
    int ans=solve(obs);
    cout<<ans;
    return 0;
}