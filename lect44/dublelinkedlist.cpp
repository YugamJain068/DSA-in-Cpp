#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
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
        head->prev=temp;
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
    temp->prev=tail;
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
    temp->next->prev=middlenode;
    temp->next=middlenode;
    middlenode->prev=temp;
}
void deletenode(int pos,node* &head){
    if(pos==1){
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;  
        delete temp;
        }
            else{
                node* curr=head;
                node* prev=NULL;
                int cnt=1;
                while(cnt<pos){
                    prev=curr;
                    curr=curr->next;
                    cnt++;
                }
                curr->prev=NULL;
                prev->next=curr->next;
                //curr->next->prev=prev;
                curr->next=NULL;
                delete curr;
    }

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
    //print(head);
    //insertathead(head,34);
    //print(head);
    //insertathead(head,12);
    //print(head);
    //insertathead(head,45);
    //print(head);

    print(head);
    insertattail(tail,34);
    print(head);
    insertattail(tail,12);
    print(head);
    insertattail(tail,45);
    print(head);
    insertatmiddle(head,tail,3,68);
    print(head);
    deletenode(2,head);
    print(head);
    return 0;
}