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
        //cout<<"memory is free for node with data: "<<val<<endl;
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
    node* travtemp=tail;
    while(travtemp->next!=NULL){
        travtemp=travtemp->next;
    }
    travtemp->next=temp;
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
node* solve(node* &first,node* &second){
    node* curr1=first;
    node* next1=curr1->next;
    node* curr2=second;
    node* next2=curr2->next;
    while(next1!=NULL && curr2!=NULL){
        if(curr2->data>=curr1->data && curr2->data<=next1->data){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}
node* sort(node* &first,node* &second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    if(first->data<=second->data){
        solve(first,second);
    }
    else{
        solve(second,first);
    }
    return first;
}
void print(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* first=new node(1);
    node* second=new node(2);
    insertattail(first,3);
    insertattail(first,5);
    insertattail(second,4);
    insertattail(second,5);
    print(first);
    print(second);
    first=sort(first,second);
    print(first);
    return 0;
}