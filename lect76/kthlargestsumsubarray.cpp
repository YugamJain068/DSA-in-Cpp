#include<iostream>
#include<queue>
using namespace std;
int solve(int arr[],int size,int k){
    priority_queue<int , vector<int> , greater<int>>mh;
    for(int i=0;i<size;i++){
        int sum=0;
        for(int j=i;j<size;j++){
            sum+=arr[j];
            if(mh.size()<k){
                mh.push(sum);
            }
            else{
                if(sum>mh.top()){
                    mh.pop();
                    mh.push(sum);
                }
            }
        }
    }
    return mh.top();
}
int main()
{
    int arr[]={1, -2, 3, -4, 5};
    int size=5,k=2;
    int ans=solve(arr,5,k);
    cout<<"kth largest sum of sub array is: "<<ans;
    return 0;
}