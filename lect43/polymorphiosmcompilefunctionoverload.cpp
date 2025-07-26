#include<iostream>
using namespace std;
class human{
    public:

    void function(int a){
        cout<<"hello"<<endl;
    }
    void function(char a){
        cout<<"hello how are you"<<endl;
    }
};
int main()
{
    human rakesh;
    rakesh.function('a');
    return 0;
}