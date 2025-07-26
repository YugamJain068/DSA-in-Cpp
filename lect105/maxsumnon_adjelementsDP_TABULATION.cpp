#include <bits/stdc++.h>
using namespace std;
int maxsum(vector<int> arr){
    int n=arr.size();
    vector<int>dp(n,0);
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        int inc=dp[i-2]+arr[i];
        int exc=dp[i-1];
        dp[i]=max(inc,exc);
    }
    return dp[n-1];
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
    int ans=maxsum(arr);
    cout<<ans;
    return 0;
}