#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
int main()
{
    node* node1=new node(24);
    cout<<"data is : "<<node1->data<<endl;
    cout<<"address of next node is : "<<node1->next<<endl;
    return 0;
}