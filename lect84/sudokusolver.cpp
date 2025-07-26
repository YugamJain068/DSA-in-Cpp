#include<iostream>
#include<vector>
using namespace std;
bool issafe(int row,int col,vector<vector<int>>&board,int val){
    for(int i=0;i<9;i++){
        //row check
        if(board[row][i]==val){
            return false;
        }
        //col check
        if(board[i][col]==val){
            return false;
        }
        //3X3 matrix xheck
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&board){
    int n=9;//lenght of row & col
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){//if cell empty
                for(int val=1;val<=9;val++){
                    if(issafe(row,col,board,val)){
                        board[row][col]=val;
                        //recursive call
                        bool moresolpossible=solve(board);
                        if(moresolpossible){
                            return true;
                        }
                        else{
                            //backtrack
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>>board(9,vector<int>(9,0));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }   
    }
    if(solve(board)){
        cout<<"the solution is: "<<endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
            }   
        cout<<endl;
        }
    }
    else{
        cout<<"no solution"<<endl;
    }
    return 0;
}