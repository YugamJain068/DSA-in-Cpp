#include <bits/stdc++.h>
using namespace std;
int solve(int n,int k){
    vector<int>dp(n+1,-1);
    dp[1]=k;
    dp[2]= k+(k*(k-1));
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-2]*(k-1))+(dp[i-1]*(k-1));
    }
    return dp[n];
}
int main()
{
    vector<int>arr;
    int n,k;
    cout<<"write n & k: ";
    cin>>n>>k;
    int ans=solve(n,k);
    cout<<ans;
    return 0;
}