#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr,int tar){
    vector<int>dp(tar+1,0);
    dp[0]=1;
    for(int i=1;i<=tar;i++){
        for(int j=0;j<arr.size();j++){
            if(i-arr[j]>=0){
                dp[i]+=dp[i-arr[j]];
            }
        }
    }
    return dp[tar];
}
int main()
{
    vector<int>arr;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    int tar;
    cin>>tar;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    int ans=solve(arr,tar);
    cout<<ans;
    return 0;
}