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
void insertathead(node* &head,int d){
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
    }
    else{
        node* temp=new node(d);
        temp->next=head;
        head=temp;
    }
}
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
void insertatmiddle(node* &head,node* &tail,int pos,int d){
    if(pos==1){
        insertathead(head,d);
        return;
    }
    node* temp=head;
    int count=1;
    while(count<(pos-1)){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
    node* middlenode=new node(d);
    middlenode->next=temp->next;
    temp->next=middlenode;
}
void reverse1(node* & head,node* curr,node* prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    node* forward=curr->next;
    reverse1(head,forward,curr);
    curr->next=prev;
}
node * reverse(node* head){
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
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
    //cout<<"data is : "<<node1->data<<endl;
    //cout<<"address of next node is : "<<node1->next<<endl;
    node* head=node1;
    node* tail=node1;
    //insertathead(head,36);
    //print(head);
    //insertathead(head,45);
    //print(head);
    insertattail(tail,36);
    print(head);            //because print function has argument as address of head.
    insertattail(tail,45);
    print(head);
    insertatmiddle(head,tail,4,22);
    print(head);
    //by iterations
    head=reverse(head);
    print(head);
    //by recursion
    reverse1(head,head,NULL);
    print(head);
    return 0;
}