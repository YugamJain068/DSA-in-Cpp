#include<iostream>
#include<stack>
using namespace std;
void sortedinsert(stack<int>&s,int num){
    if((!s.empty() && s.top()<num) ||s.empty()){
        s.push(num);
        return ;
    }
    int num2=s.top();
    s.pop();
    sortedinsert(s,num);
    s.push(num2);
}
void emptystack(stack<int>&s){
    if(s.empty()){
        return ;
    }
    int num=s.top();
    s.pop();
    emptystack(s);
    sortedinsert(s,num);
}
int main()
{
    stack<int>s;
    s.push(5);
    s.push(4);
    s.push(6);
    s.push(3);
    s.push(3);
    s.push(10);
    s.push(8);
    emptystack(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}