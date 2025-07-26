#include<iostream>
using namespace std;
int swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
main()
{
    int arr[100],n;
        cout<<"write size of array"<<endl;
        cin>>n;
        for(int i=0;i<=n-1;i++)
        {
            cout<<"write the value of "<<i+1<<" index: "<<endl;
            cin>>arr[i];
        }
    for(int i=0;i<(n-1);i++)
    {
        int minindex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[minindex]>arr[j])
            minindex=j;
        }
        swap(&arr[minindex],&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<endl<<arr[i]<<endl;
    }
}