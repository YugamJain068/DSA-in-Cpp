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
void splitlist(node* &tail,node* &tail2){
    int nodes_no=0;
    node* temp=tail;
    do{
        tail=tail->next;
        nodes_no++;
    }while(tail!=temp);
    node* temp1=tail;
    int cnt=1;
    while(cnt<nodes_no){
        temp1=temp1->next;
        cnt++;
    }
    tail2=temp1->next;
    temp1->next=NULL;
    node* temp2=tail2;
    while(temp2->next!=tail){
        temp2=temp2->next;
    }
    temp2->next=NULL;
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
    insertnode(tail,3,7);
    insertnode(tail,7,9);   
    insertnode(tail,9,11);  
    insertnode(tail,7,8);
    insertnode(tail,3,1);
    printnode(tail);
    node* tail2=NULL;
    splitlist(tail,tail2);
    printnode(tail);
    printnode(tail2);
}