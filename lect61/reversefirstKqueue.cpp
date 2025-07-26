#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int k=3;
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    stack<int>s;
    for(int i=0;i<k;i++){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int element=s.top();
        s.pop();
        q.push(element);
    }
    int t=5-k;
    for(int i=0;i<t;i++){
        int element=q.front();
        q.pop();
        q.push(element);
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}