#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool solve(int n,int arr[],int sum){
    vector<int>curr(sum+1,0);
    vector<int>next(sum+1,0);
    curr[0]=1;
    next[0]=1;
    for(int index=n-1;index>=0;index--){
        for(int target=0;target<=sum/2;target++){
            bool inc=0;
            if(target-arr[index]>=0){
                inc=next[target-arr[index]];
            }
            bool exc=next[target-0];
            curr[target]=inc or exc;
        }
        next=curr;
    }
    return next[sum/2];
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