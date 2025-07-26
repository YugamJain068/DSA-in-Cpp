#include<iostream>
#include<queue>
using namespace std;
int kthsmallest(int arr[],int size,int k){
    priority_queue<int>heap;
    //creating a maxheap for first kth element
    for(int i=0;i<k;i++){
        heap.push(arr[i]);
    }
    //for rest of element
    for(int i=k;i<size;i++){
        if(arr[i]<heap.top()){
            heap.pop();
            heap.push(arr[i]);
        }
    }
    int ans=heap.top();
    return ans;
}
int main()
{
    int arr[5]={7,10,4,20,15};
    int size=5,k;
    cout<<"write the value of k: ";
    cin>>k;
    int ans=kthsmallest(arr,size,k);
    cout<<"kth smallest element of this array is: "<<ans;
    return 0;
}