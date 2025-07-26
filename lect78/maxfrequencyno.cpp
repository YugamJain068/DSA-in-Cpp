#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int maxfreq(vector<int>arr,int size){
    unordered_map<int,int>count;
    int maxfrequency=0;
    int ans=0;
    for(int i=0;i<size;i++){
        count[arr[i]]++;
        maxfrequency=max(maxfrequency,count[arr[i]]);
    }
    for(int i=0;i<size;i++){
        if(count[arr[i]]==maxfrequency){
            ans=arr[i];
            break;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={1,2,1,3,3,1,2,4,4,1};
    int size=10;
    int ans=maxfreq(arr,size);
    cout<<ans<<endl;
    return 0;
}