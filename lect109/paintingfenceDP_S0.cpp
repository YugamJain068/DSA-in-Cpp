#include <bits/stdc++.h>
using namespace std;
int solve(int n,int k){
    vector<int>dp(n+1,-1);
    int prev2=k;
    int prev1= k+(k*(k-1));
    for(int i=3;i<=n;i++){
        int curr=(prev2*(k-1))+(prev1*(k-1));
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
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