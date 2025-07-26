#include<iostream>
using namespace std;
int leftsearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    int ans=-1;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]>key)
        {
            end=mid-1;
        }
        else{
            start=start+1;
        }
        mid=start+((end-start)/2);
        
    }
    return ans;
}    
int rightsearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    int ans=-1;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            start=mid+1;
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
    return ans;
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
            cout<<"write the value of "<<i<<" index: "<<endl;
            cin>>arr[i];
        }
        int leftindex=leftsearch(arr,size,key);
        int rightindex=rightsearch(arr,size,key);
        cout<<"the left most "<<key<<" is at "<<leftindex<<" and the right most "<<key<<" is at "<<rightindex;
        
        
    }

