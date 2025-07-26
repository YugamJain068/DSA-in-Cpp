#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return ;
    }
    int num=s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(num);
}
void reversestack(stack<int>&s){
    if(s.empty()){
        return ;
    }
    int num=s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s,num);
}
int main()
{
    stack<int>s;
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(10);
    reversestack(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}