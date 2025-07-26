#include<iostream>
#include<queue>
using namespace std;
//node creation for B.T
class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void buildlevelordertraversal(node* &root){
    queue<node*>q;
    cout<<"enter the data of root: ";
    int rootdata;
    cin>>rootdata;
    root=new node(rootdata);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"enter the data of left child of "<<temp->data<<" : ";
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"enter the data of right child of "<<temp->data<<" : ";
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main()
{
    node* root=NULL;
    buildlevelordertraversal(root);
    levelordertraversal(root);
}