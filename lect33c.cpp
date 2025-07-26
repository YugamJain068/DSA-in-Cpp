#include<iostream>
using namespace std;
bool linearsearch(int arr[],int size,int key)
{
    if(size==0){
        return false;
    }
    if(key==arr[0]){
        return true;
    }
    else{
        return linearsearch(arr+1,size-1,key);
    }
    }
int main()
{
    int arr[7]={2,0,3,6,5,8,7};
    int size=7;
    int key;
    cin>>key;
    bool ans=linearsearch(arr,size,key);
    if(ans){
        cout<<"key is found";
    }
    else{
        cout<<"key is not found";
    }
    return 0;
}