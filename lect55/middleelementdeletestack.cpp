#include<iostream>
#include<stack>
using namespace std;
void middledelete(stack<int>&s,int size,int count){
    if(count==size/2){
        s.pop();
        return ;
    }
    int num=s.top();
    s.pop();
    middledelete(s,size,count+1);
    s.push(num);
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
    int size=s.size();
    middledelete(s,size,0);
    for(int i=0;i<size;i++){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}