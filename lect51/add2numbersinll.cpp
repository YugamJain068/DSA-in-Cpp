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
void insertattail(node* &head,node* &tail,int d){
    node* temp=new node(d);
    if(head==NULL){
        tail=temp;
        head=temp;
    }
    else{
    node* travtemp=tail;
    while(travtemp->next!=NULL){
        travtemp=travtemp->next;
    }
    travtemp->next=temp;
    }
}
void reverse(node* &head){
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
}
node* add(node* first,node* second){
    int carry=0;
    node* anshead=NULL;
    node* anstail=NULL;
    while(first!=NULL || second!=NULL || carry!=0){
        int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
                int sum = carry + val1 + val2;
                int digit = sum%10;
                insertattail(anshead,anstail,digit);
                 carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
    } 
    return anshead;
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
    node* first=new node(4);
    node* second=new node(3);
    insertattail(first,first,5);
    insertattail(second,second,4);
    insertattail(second,second,5);
    print(first);
    print(second);
    reverse(first);
    reverse(second);
    print(first);
    print(second);
    node* ans=add(first,second);
    print(ans);
    reverse(ans);
    print(ans);
    return 0;
}