#include<iostream>
using namespace std;
class stack{
    public:
    // data
    int top;
    int* arr;
    int size;

    //behaviour
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflowed"<<endl;
            
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    stack st(5);
    st.push(34);
    st.push(56);
    st.push(78);
    cout<<"the element at top is: "<<st.peek()<<endl;
    st.pop();
    cout<<"the element at top is: "<<st.peek()<<endl;
    st.pop();
    cout<<"the element at top is: "<<st.peek()<<endl;
    st.pop();
    st.pop();
    cout<<"the element at top is: "<<st.peek()<<endl;
    if(st.empty()){
        cout<<"empty"<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
    return 0;
}