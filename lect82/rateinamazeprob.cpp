#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool issafe(int newx,int newy,vector<vector<int>>&arr,int n,vector<vector<bool>>&vis){
    if(newx>=0 && newx<n && newy>=0 && newy<n && arr[newx][newy]==1 && vis[newx][newy]!=1){
        return true;
    }
    return false;
}
void solve(int x,int y,vector<vector<int>>&arr,int n,vector<vector<bool>>&vis,string path,vector<string>&ans){
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return ;
    }
    //we have total 4 movements i.e in order ---> D , L , R , U
    vis[x][y]=1;
    //down
    if(issafe(x+1,y,arr,n,vis)){
        solve(x+1,y,arr,n,vis,path+'D',ans);
    }
    //left
    if(issafe(x,y-1,arr,n,vis)){
        solve(x,y-1,arr,n,vis,path+'L',ans);
    }
    //right
    if(issafe(x,y+1,arr,n,vis)){
        solve(x,y+1,arr,n,vis,path+'R',ans);
    }
    //up
    if(issafe(x-1,y,arr,n,vis)){
        solve(x-1,y,arr,n,vis,path+'U',ans);
    }
    vis[x][y]=0;
}
vector<string> ratmaze(vector<vector<int>>&arr,int n){
    vector<string>ans;
    vector<vector<bool>>vis(n,vector<bool>(n,0));
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,vis,path,ans);
    return ans;
}
int main()
{
    vector<vector<int>>arr={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    int n=4;
    vector<string>ans;
    ans=ratmaze(arr,n);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}