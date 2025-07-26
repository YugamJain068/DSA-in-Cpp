#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+((end-start)/2);
        
    }
    return -1;
}  
 int findPeak(int arr[], int n) {

    int s =0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {
        //cout<<" s " << s <<" e " << e << endl;
        if(arr[mid] < arr[mid+1]){
            s = mid+1; 
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}  
    int main()
    {
        int arr[100],size,key;
        cout<<"write size of array"<<endl;
        cin>>size;
        cout<<"write key"<<endl;
        cin>>key;
        for(int i=0;i<=size-1;i++)
        {
            cout<<"write the value of "<<i+1<<" index: "<<endl;
            cin>>arr[i];
        }
        int index=binarysearch(arr,size,key);
        cout<<"the number "<<key<<" is found at "<<index+1<<endl;
        cout<<findPeak(arr,size);
    }

