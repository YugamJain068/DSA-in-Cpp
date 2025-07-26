#include<iostream>
using namespace std;
bool binarysearch(int arr[],int key,int start,int end)
{   
    if(start>end){
        return false;
    }
    int mid=start+((end-start)/2);
        if(key==arr[mid]){
            return true;
        }
        if(key<arr[mid]){
            return binarysearch(arr,key,start,mid-1);
        }
        else{
            return binarysearch(arr,key,mid+1,end);
        }
}
int main()
{
    int arr[7]={2,3,5,7,9,11,14};
    int size=7,key,start=0,end=size-1;
    cin>>key;
    bool ans=binarysearch(arr,key,start,end);
    if(ans){
        cout<<"key is found";
    }
    else{
        cout<<"key is not found";
    }
    return 0;
}