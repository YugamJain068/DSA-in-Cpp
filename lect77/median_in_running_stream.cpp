#include<iostream> 
#include<vector> 
#include<queue> 
using namespace std;
int signum(int a, int b){
    if(a==b){
        return 0;
    }
    else if(a>b){
        return 1;
    }
    return -1;
}
int callmedian(int element,priority_queue<int>&maxheap ,priority_queue<int , vector<int> , greater<int>>&minheap,int median){
        switch(signum(maxheap.size(),minheap.size())){
            case 0:
            if(element>median){
                minheap.push(element);
                median=minheap.top();
            }
            else{
                maxheap.push(element);
                median=maxheap.top();
            }
            break;
            case 1:
            if(element>median){
                minheap.push(element);
                median=(maxheap.top()+minheap.top())/2;
            }
            else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(element);
                median=(maxheap.top()+minheap.top())/2;
            }
            break;
            case -1:
            if(element>median){
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(element);
                median=(maxheap.top()+minheap.top())/2;
            }
            else{
                maxheap.push(element);
                median=(maxheap.top()+minheap.top())/2;
            }
            break;
        }
        return median;
}
vector<int>solve(vector<int>&arr,int size){
    vector<int>ans;
    priority_queue<int>maxheap;
    priority_queue<int , vector<int> , greater<int>>minheap;
    int median=0;
    for(int i=0;i<size;i++){
        median=callmedian(arr[i],maxheap,minheap,median);
        ans.push_back(median);
    }
    return ans;
}
int main()
{
    vector<int>arr={5,3,1,2,8,6};
    int size=6;
    vector<int>ans;
    ans=solve(arr,size);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}