#include<iostream>
using namespace std;
bool ispresent(int arr[][3],int target,int i,int j)
{
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}
int printsum(int arr[][3])
{
    int row=-1;
    int maxrow=-1;
    int max=INT_MIN;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=arr[i][j];
        }
        cout<<sum<<" ";
        if(sum>max){
            max=sum;
            maxrow=i;
        }
    }
    cout<<"the maximum row is "<<maxrow+1;
}
int main()
{
    int arr[3][3];
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"write the number to search"<<endl;
    cin>>target;
    if(ispresent(arr,target,3,3))
    {
        cout<<"number is present"<<endl;
    }
    else{
        cout<<"number is not present"<<endl;
    }
    printsum(arr);
    
}