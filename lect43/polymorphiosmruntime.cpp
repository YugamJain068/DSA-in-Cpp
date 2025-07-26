#include<iostream>
using namespace std;
class a{
    public:
    void speak(){
        cout<<"speaking"<<endl;
    }
};
class b: public a{
    public:
    void speak(){
        cout<<"barking"<<endl;
    }
};
int main()
{
    b obj1;
    obj1.speak();
    return 0;
}