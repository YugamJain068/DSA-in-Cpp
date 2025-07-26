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
            this->next=NULL;
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
void middleofnode(node* head){
    int len=0;
    node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    int ans=len/2+1;
    temp=head;
    int cnt=1;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    cout<<temp->data;
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
    insertattail(tail,38);          
    insertattail(tail,33);          
    insertattail(tail,22);          
    print(head);
    middleofnode(head);
}