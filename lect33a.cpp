#include<iostream>
using namespace std;
bool issorted(int arr[],int size)
{
    if(size==0 || size==1){
    return true;}
    if(arr[0]>arr[1]){
    return false;}
    else
    {
    return issorted(arr+1,size-1);
    }
}
int main()
{
    int arr[5]={3,6,11,12,14};
    int size=5;
    bool ans=issorted(arr,size);
    if(ans){
    cout<<"array is sorted";}
    else{
    cout<<"array is not sorted";}
    return 0;
}