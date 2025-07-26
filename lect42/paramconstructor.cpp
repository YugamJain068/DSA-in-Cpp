#include<iostream>
//#include"hero.cpp"
using namespace std;
class hero{
    private:
    int health;
    char level;
    public:
    //default constructor
    hero(){
        cout<<"constructor is created"<<endl;
    }
    //parametrised constructor
    hero(int health,char level){
        cout<<"the value of this is: "<<this<<endl;
        this->health=health;
        this->level=level;
    }
    void print(){
        cout<<"health: "<<this->health<<endl;
        cout<<"level: "<<this->level<<endl;
    }
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    /*void sethealth(int h){
        health=h;                 ***no need of these 
    }
    void setlevel(char lev){
        level=lev;
    }*/
};
int main()
{
    //statically
    hero ramesh(12,'A');
    //ramesh.sethealth(70);      ***no need of these
    //ramesh.setlevel('A');

    hero suresh(ramesh);
    ramesh.print();
    suresh.print();
    //dynamically
    hero *rahul=new hero(14,'B');
    cout<<"the address of ramesh is: "<<&ramesh<<endl;
    cout<<"size : "<<sizeof(ramesh)<<endl;
    rahul->print();
    /*cout<<"the health of ramesh is: "<<ramesh.gethealth()<<endl;
    cout<<"the level of ramesh is: "<<ramesh.getlevel()<<endl;
    cout<<"the health of rahul is: "<<rahul->gethealth()<<endl;
    cout<<"the level of rahul is: "<<rahul->getlevel()<<endl;*/
    return 0;
}