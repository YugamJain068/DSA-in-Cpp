#include<iostream>
//#include"hero.cpp"
using namespace std;
class hero{
    private:
    int health;
    char level;
    public:
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void sethealth(int h){
        health=h;
    }
    void setlevel(char lev){
        level=lev;
    }
};
int main()
{
    hero ramesh;
    ramesh.sethealth(70);
    ramesh.setlevel('A');
    cout<<"size : "<<sizeof(ramesh)<<endl;
    cout<<"the health of ramesh is: "<<ramesh.gethealth()<<endl;
    cout<<"the level of ramesh is: "<<ramesh.getlevel()<<endl;
    return 0;
}