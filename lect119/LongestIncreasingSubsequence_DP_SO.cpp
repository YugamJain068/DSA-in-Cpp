#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&a){
    int n=a.size();
    vector<int>currrow(n+1,0);
    vector<int>nextrow(n+1,0);
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int inc=0;
            if(prev==-1 || a[curr]>a[prev]){
                inc=1+nextrow[curr+1];           //curr+1--->because -1 index will not be valid as prev is changed to current
            }
            //not include
            int exc=0+nextrow[prev+1];           //prev+1--->because -1 index will not be valid
            currrow[prev+1]=max(inc,exc);          //prev+1--->because -1 index will not be valid
        }
        nextrow=currrow;
    }
    return nextrow[0];        //-1+1=0
}
int solveoptimal(vector<int>&a){                    //solving using DP with Binary Search
    int n=a.size();
    if(n==0){
        return 0;
    }
    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>ans.back()){
            ans.push_back(a[i]);
        }
        else{
            //finding index of just bada element to a[i] in ans
            int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
            ans[index]=a[i];
        }
    }
    return ans.size();
}
int main()
{
    int n;
    cout<<"write size of satisfaction vector: ";
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //int ans=solve(a);
    int ans=solveoptimal(a);
    cout<<ans;
    return 0;
}