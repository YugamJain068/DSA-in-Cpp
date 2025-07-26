#include <bits/stdc++.h>
using namespace std;
int maxsum(vector<int> arr,int n,vector<int>dp){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return arr[0];
    }
    //step 3
    if(dp[n]!=-1){
        return dp[n];
    }
    int inc=maxsum(arr,n-2,dp)+arr[n];
    int exc=maxsum(arr,n-1,dp);
    //step 2
    dp[n]=max(inc,exc);
    return dp[n];
}
int main()
{
    vector<int>arr;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    //going right to left in array
    //step 1
    vector<int>dp(size,-1);
    int ans=maxsum(arr,size-1,dp);
    cout<<ans;
    return 0;
}