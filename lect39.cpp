#include<iostream>
#include<vector>
using namespace std;
void swap(int *input,int *j){
    int temp=*input;
    *input=*j;
    *j=temp;
}
void function(vector<int> &input,int index,vector<vector<int>> &ans){
    if(index>=input.size()){
       ans.push_back(input);
    }
    
    for(int i=index;i<input.size();i++){
       swap(&input[index],&input[i]);
       function(input,index+1,ans);
       //backtrack
       swap(&input[index],&input[i]);
    }
}
int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);
    int index=0;
    vector<vector<int>> ans;
    function(input,index,ans);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}