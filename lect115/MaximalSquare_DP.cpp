//code incomplete
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>&mat,int i,int j,int &maxi){

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[n][m];
        }
    }
    int maxi=0;
    solve(mat,0,0,maxi);
    cout<<maxi;
    return 0;
}