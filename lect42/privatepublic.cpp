#include<iostream>
//#include"hero.cpp"
using namespace std;
class hero{
    public:
    int health;
    //private:
    char level;
    void function(){
        cout<<level<<endl;
    }
};
int main()
{
    hero ramesh;
    ramesh.health=100;
    ramesh.level='A';
    cout<<"size : "<<sizeof(ramesh)<<endl;
    cout<<"the health of ramesh is: "<<ramesh.health<<endl;
    cout<<"the level of ramesh is: "<<ramesh.level<<endl;
    return 0;
}