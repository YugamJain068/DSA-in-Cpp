#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextsmall(int arr[],int size){
    stack<int>s;
    s.push(-1);
    vector<int>ans;
    for(int i=size-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(curr);
    }
    
    return ans;
}
int main()
{
    int arr[7]={4,5,3,2,5,1,6};
    vector<int>ans=nextsmall(arr,7);
    for (int i = ans.size()-1; i>=0; i--) {
        cout << ans[i] << endl;
    }
    return 0;
}