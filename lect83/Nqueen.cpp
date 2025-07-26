#include<iostream>
#include<vector>
using namespace std;
void addsolution(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool issafe(int row,int col,vector<vector<int>>&board,int n){
    int x=row;
    int y=col;
    //left direction check
    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }
    x=row;
    y=col;
    while(y>=0 && x>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x=row;
    y=col;
    while(y>=0 && x<n){
        if(board[x][y]==1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}
void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    //base case
    if(col==n){
        addsolution(board,ans,n);
        return ;
    }
    for(int row=0;row<n;row++){
        if(issafe(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,board,ans,n);
            //while backtracking
            board[row][col]=0;
        }
    }
}
int main()
{
    vector<vector<int>>board(4,vector<int>(4,0));
    vector<vector<int>>ans;
    int n=4;
    solve(0,board,ans,n);
    for (int k = 0; k < ans.size(); k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[k][i * n + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
    return 0;
}