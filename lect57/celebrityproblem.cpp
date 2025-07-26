#include<iostream>
#include<stack>
using namespace std;
bool aknowsb(int arr[][3],int a,int b){
    if(arr[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}
int celebrity(int arr[][3],int n){
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(aknowsb(arr,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ans=s.top();
    int zerocount=0;
    for(int i=0;i<n;i++){
        if(arr[ans][i]==0){
            zerocount++;
        }
    }
    if(zerocount!=n){
        return -1;
    }
    int onecount=0;
    for(int i=0;i<n;i++){
        if(arr[i][ans]==1){
            onecount++;
        }
    }
    if(onecount!=n-1){
        return -1;
    }
    return ans;
}
int main()
{
    int arr[3][3]={{0,0,1},{0,0,1},{0,0,0}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"celebrity is "<<celebrity(arr,3)<<endl;    
    return 0;
}