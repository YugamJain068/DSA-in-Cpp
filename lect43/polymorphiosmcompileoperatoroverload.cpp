#include<iostream>
using namespace std;
class A{
    public:

    int a;

    void operator+(A &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"output: "<< (value2-value1)<<endl;
    }
    void operator() (){
        cout<<"bracket is used"<<endl;
    }
};
int main()
{
    A obj1,obj2;
    obj1.a=5;
    obj2.a=8;
    obj1 + obj2;
    obj1();

    return 0;
}