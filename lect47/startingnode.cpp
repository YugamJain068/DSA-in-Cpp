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
void insertattail(node* &tail,int d){
    if(tail==NULL){
        node* temp=new node(d);
        tail=temp;
    }
    else{
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
    }
}
node* detectcycle(node* &head){
    if(head==NULL){
        return NULL;
    }
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
node* startingnode(node* &head){
    if(head==NULL){
        return NULL;
    }
        node* intersection=detectcycle(head);
        node* slow=head;
        while(slow!=intersection){
            slow=slow->next;
            intersection=intersection->next;
        }
    return slow;
}
void print(node* &head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* node1=new node(24);
    node* head=node1;
    node* tail=node1;
    insertattail(tail,36);          
    insertattail(tail,45);
    insertattail(tail,22);
    print(head);
    tail->next=head->next->next;
    node* loop=startingnode(head);
    cout<<"starting node present at: "<<loop->data<<endl;
    return 0;
}