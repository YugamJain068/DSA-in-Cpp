#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr,int size, int index){
    int largest=index;
    int leftindex=2*index+1;                //change due to 0 based indexing
    int rightindex=2*index+2;               //change due to 0 based indexing
    if(leftindex < size && arr[leftindex] > arr[largest]){              //change due to 0 based indexing
        //update largest
        largest=leftindex;
    }
    if(rightindex < size && arr[rightindex] > arr[largest]){            //change due to 0 based indexing
        //update largest
        largest=rightindex;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}
vector<int> merge(vector<int>&h1,vector<int>&h2){
    //merge the vectors
    vector<int>ans;
    for(auto i:h1){
        ans.push_back(i);
    }
    for(auto i:h2){
        ans.push_back(i);
    }
    //vector to heap using heapify algorithm
    int size=ans.size();
    for(int i=size/2-1;i>=0;i--){           //0 based indexing
        heapify(ans,size,i);
    }
    return ans;
}
int main()
{
    vector<int>h1={10,5,6,2};
    vector<int>h2={12,7,9};
    vector<int>ans;
    ans=merge(h1,h2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}