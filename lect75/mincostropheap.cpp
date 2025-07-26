#include<iostream>
#include<queue>
using namespace std;
long long mincost(long long arr[],long long size){
    //creating a minheap
    priority_queue<long long , vector<long long> , greater<long long>>mh;
    for(int i=0;i<size;i++){
        mh.push(arr[i]);
    }
    long long cost=0;
    while(mh.size()>1){
        long long a=mh.top();
        mh.pop();
        long long b=mh.top();
        mh.pop();
        long long sum=a+b;
        cost+=sum;
        mh.push(sum);
    }
    return cost;
}
int main()
{
    long long arr[]={4,3,2,6};
    long long size=4;
    long long ans=mincost(arr,size);
    cout<<"min cost is: "<<ans<<endl;
    return 0;
}