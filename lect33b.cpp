#include<iostream>
using namespace std;
int sumofarray(int arr[],int size)
{
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    return arr[0]+sumofarray(arr+1,size-1);
}
int main()
{
    int arr[5]={2,4,3,6,5};
    int size=5;
    cout<<sumofarray(arr,size);
    return 0;
}