#include<iostream>
using namespace std;
class human{
    public:
    int height;
    int weight;
    int age;
    
    public:

    int getheight(){
        return this->height;
    }
    void setweight(int w){
        this->weight=w;
    }
};
class male:public human{
    public:
    string colour;

    public:

    string getcolour(){
        return this->colour;
    }
};
int main()
{
    male rahul;
    rahul.height=12;
    rahul.weight=55;
    rahul.colour="white";
    cout<<"height: "<<rahul.height<<endl;
    cout<<"weight: "<<rahul.weight<<endl;
    cout<<"colour: "<<rahul.colour<<endl;
    return 0;
}