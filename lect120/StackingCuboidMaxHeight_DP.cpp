#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>base,vector<int>newbox){
    if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]){
        return true;
    }
    return false;
}
int solve(vector<vector<int>>&a){
    int n=a.size();
    vector<int>currrow(n+1,0);
    vector<int>nextrow(n+1,0);
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int inc=0;
            if(prev==-1 || check(a[curr],a[prev])){
                inc=a[curr][2]+nextrow[curr+1];           //curr+1--->because -1 index will not be valid as prev is changed to current
            }
            //not include
            int exc=0+nextrow[prev+1];           //prev+1--->because -1 index will not be valid
            currrow[prev+1]=max(inc,exc);          //prev+1--->because -1 index will not be valid
        }
        nextrow=currrow;
    }
    return nextrow[0];        //-1+1=0
}
int maxheight(vector<vector<int>>&cuboids){
    //step 1 ---> sorting all dimensions for every cuboids
    for(auto &a:cuboids){
        sort(a.begin(),a.end());
    } 
    //step 2 ---> sort the cuboids on the basis of their width
    sort(cuboids.begin(),cuboids.end());
    int ans=solve(cuboids);
    return ans;
}
int main()
{
    int n;
    cout<<"write no. of cuboids: ";
    cin>>n;
    vector<vector<int>>cuboids(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>cuboids[i][j];
        }
    }
    int ans=maxheight(cuboids);
    cout<<ans;
    return 0;
}