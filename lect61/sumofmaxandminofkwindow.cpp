#include<iostream>
#include<queue>
using namespace std;
int solve(int arr[],int n,int k){
    //creation of deque to track max and min
    //maxi and mini will contain indexis elemnt of array in dec and inc order respectively
    deque<int>maxi;
    deque<int>mini;
    //fill maxi and mini for first window
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans=0;
    //store the sum of max and min of window 1 in answer
    ans+=arr[maxi.front()]+arr[mini.front()];
    //next window
    for(int i=k;i<n;i++){
        //removal
        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }
        //addition
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        ans+=arr[maxi.front()]+arr[mini.front()];
    }
    return ans;
}
int main()
{
    int k=4;
    int arr[7]={2,5,-1,7,-3,-1,-2};
    cout<<solve(arr,7,k);
    return 0;
}