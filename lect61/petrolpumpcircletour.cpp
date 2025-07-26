#include<iostream>
#include<queue>
struct pump{
        int petrol;
        int distance;
};
using namespace std;
int main()
{
    int n;
    cout<<"write number of petrol pumps"<<endl;
    cin>>n;
    struct pump arr[n];
    for(int i=0;i<n;i++){
        cout<<"write petrol amount and distance of "<<i+1<<" petrol pump"<<endl;
        cin>>arr[i].petrol;
        cin>>arr[i].distance;
    }
    int start=0,balance=0,deficit=0;
    for(int i=0;i<n;i++){                           //i ---> rear
        balance+=arr[i].petrol-arr[i].distance;
        if(balance<0){
            deficit+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(deficit+balance>=0){
        cout<<start;
    }
    else{
        cout<<"not possible";
    }
    return 0;
}