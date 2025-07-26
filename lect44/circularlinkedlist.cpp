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
void deletenode(node* & tail,int element){
    if(tail==NULL){
        cout<<"list is empty, please check again"<<endl;
    }
    else{
        node* prev=tail;
        node* curr=prev->next;
        while(curr->data != element){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        // to delete 1 node list
        if(curr==prev){
            tail=NULL;
        }
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
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
    deletenode(tail,3);
    printnode(tail);
    deletenode(tail,8);
    printnode(tail);
}