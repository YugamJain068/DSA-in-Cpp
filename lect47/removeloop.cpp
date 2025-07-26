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
void deletenode(int pos,node* &head){
    if(pos==1){
        node* temp=head;
        head=head->next;
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
                prev->next=curr->next;
                curr->next=NULL;
                delete curr;
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
void removeloop(node* &head){
    if(head==NULL){
        return ;
    }
    node* startofloop=startingnode(head);
    if(startofloop==NULL){
        return ;
    }
    node* temp=startofloop;
    while(temp->next!=startofloop){
        temp=temp->next;
    }
    temp->next=NULL;
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
    print(head);           
    insertattail(tail,45);
    print(head);
    insertatmiddle(head,tail,4,22);
    print(head);
    tail->next=head->next;
    node* loop=startingnode(head);
    cout<<"starting node present at: "<<loop->data<<endl;
    removeloop(head);
    print(head);
    return 0;
}