#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int pivot(int arr[],int s,int e){
    int piv=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=piv){
            count++;
        }
    }
    int pivotindex = s + count;
    swap(arr[pivotindex],arr[s]);
    int i=s,j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<piv){
            i++;
        }
        while(arr[j]>piv){
            j--;
        }
       if(i<pivotindex && j>pivotindex) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
    }
}
 return pivotindex;
}
void partition(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int p=pivot(arr,s,e);
    partition(arr,s,p-1);
    partition(arr,p+1,e);
}
int main()
{
    int arr[8]={4,12,2,8,0,3,10,2};
    int n=8;
    partition(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}