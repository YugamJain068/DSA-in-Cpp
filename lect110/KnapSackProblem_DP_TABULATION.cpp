#include <bits/stdc++.h>
using namespace std;
int sacksolve(vector<int> &weights,vector<int> &values,int size,int capacity){
    vector<vector<int>>dp(size,vector<int>(capacity+1,-1));
    //step 1 ---> base case analysis
    for(int w=weights[0];w<=capacity;w++){
        if(weights[0]<=capacity){
            dp[0][w]=values[0];
        }
        else{
            dp[0][w]=0;
        }
    }
    for(int index=1;index<size;index++){
        for(int w=0;w<=capacity;w++){
            int include=0;
            if(weights[index]<=w){
                include=values[index]+dp[index-1][w-weights[index]];
            }
            int exclude=0+dp[index-1][w];
            dp[index][w]=max(include,exclude);
        }
    }
    return dp[size-1][capacity];
}
int main()
{
    vector<int>weights,values;
    int size;
    cout<<"write size of vector: ";
    cin>>size;
    cout<<"write weights: "<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        weights.push_back(data);
    }
    cout<<"write values: "<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        values.push_back(data);
    }
    cout<<"write maxweight: ";
    int maxweight;
    cin>>maxweight;
    int ans=sacksolve(weights,values,size,maxweight);
    cout<<ans;
    return 0;
}