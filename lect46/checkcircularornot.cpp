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
    ~node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next==NULL;
        }
        cout<<"memory is free for node with data: "<<val<<endl;
    }
};
void insertnode(node* &tail,int element,int d){
    if(tail==NULL){
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
bool iscircular(node* &head){
    if(head==NULL){
        return true;
    }
    node* temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==NULL){
        return false;
    }
    else if(temp==head){
        return true;
    }
}
void printnode(node* &tail){
    node* temp=tail;
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}
int main()
{
    node* node1=NULL;
    node* tail=node1;
    insertnode(tail,5,3);
    printnode(tail);
    insertnode(tail,3,7);
    printnode(tail);
    insertnode(tail,7,9);
    printnode(tail);
    insertnode(tail,9,11);
    printnode(tail);
    insertnode(tail,7,8);
    printnode(tail);
    insertnode(tail,3,1);
    printnode(tail);
    if(iscircular(tail)){
        cout<<"the linked list is circular"<<endl;
    }
    else{
        cout<<"the linked list is not circular"<<endl;
    }
}