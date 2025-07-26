#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&pizza){
    int k=pizza.size();
    vector<vector<int>>dp1(k+2,vector<int>(k+2,0));
    vector<vector<int>>dp2(k+2,vector<int>(k+2,0));
    for(int index=k-2;index>=0;index--){
        for(int n=1;n<=k/3;n++){
            int inc=pizza[index]+dp1[index+2][n-1];
            int exc=0+dp1[index+1][n];
            dp1[index][n]=max(inc,exc);
        }
    }
    int case1=dp1[0][k/3];
    for(int index=k-1;index>=1;index--){
        for(int n=1;n<=k/3;n++){
            int inc=pizza[index]+dp2[index+2][n-1];
            int exc=0+dp2[index+1][n];
            dp2[index][n]=max(inc,exc);
        }
    }
    int case2=dp2[1][k/3];
    return max(case1,case2);
}
int main()
{
    int k;
    cout<<"write the total no. of slices in pizza: ";
    cin>>k;
    vector<int>pizza(k);
    for(int i=0;i<pizza.size();i++){
        cin>>pizza[i];
    }
    int ans=solve(pizza);
    cout<<ans;
    return 0;
}