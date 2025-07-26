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
void print(node* &head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* sort012(node* &head){
    node* zerohead=new node(-1);
    node* zerotail=zerohead;
    node* onehead=new node(-1);
    node* onetail=onehead;
    node* twohead=new node(-1);
    node* twotail=twohead;
    node* curr=head;
    while(curr!=NULL){
        if(curr->data==0){
            insertattail(zerotail,0);
            print(zerohead);
        }
        else if(curr->data==1){
            insertattail(onetail,1);
            print(onehead);
        }
        else if(curr->data==2){
            insertattail(twotail,2);
            print(twohead);
        }
        curr=curr->next;
    }
    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;
    head=zerohead->next;
    //delete zerohead;
    //delete onehead;
    //delete twohead;
    return head;
}
int main()
{
    node* node1=new node(1);
    node* tail=node1;
    node* head=node1;
    insertattail(tail,0);
    insertattail(tail,2);
    insertattail(tail,1);
    insertattail(tail,2);
    print(head);
    sort012(head);
    print(head);
    return 0;
}