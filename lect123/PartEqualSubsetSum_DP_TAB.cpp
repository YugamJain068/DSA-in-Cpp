#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool solve(int n,int arr[],int sum){
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int index=n-1;index>=0;index--){
        for(int target=0;target<=sum/2;target++){
            bool inc=0;
            if(target-arr[index]>=0){
                inc=dp[index+1][target-arr[index]];
            }
            bool exc=dp[index+1][target-0];
            dp[index][target]=inc or exc;
        }
    }
    return dp[0][sum/2];
}
int main()
{
    int n;
    cout<<"write size of array: ";
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%2!=0){
        cout<<"no"<<endl;
    }
    else{
        if(solve(n,arr,sum)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}