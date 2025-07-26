#include<iostream>
#include<queue>
using namespace std;
main()
{
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    maxi.push(2);
    maxi.push(6);
    maxi.push(4);
    maxi.push(7);
    maxi.push(5);
    int n=maxi.size();
    for(int i=0;i<n;i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<"\n\n";
    mini.push(2);
    mini.push(6);
    mini.push(4);
    mini.push(7);
    mini.push(5);
    n=mini.size();
    for(int i=0;i<n;i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl<<mini.empty()<<endl;
}