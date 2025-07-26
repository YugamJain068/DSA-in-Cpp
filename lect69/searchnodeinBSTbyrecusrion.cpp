#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    //constructor
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
node* insertintoBST(node* root,int d){
    //BASE CASE
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d<root->data){
        //left call 
        root->left=insertintoBST(root->left,d);
    }
    else{
        //right call 
        root->right=insertintoBST(root->right,d);
    }
    return root;
}
void insertroot(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertintoBST(root,data);
        cin>>data;
    }
}
bool searchnode(node* root,int x){
    //BASE CASE
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    //RECURSIVE CALL
    if(x<root->data){
        return searchnode(root->left,x);
    }
    else{
        return searchnode(root->right,x);
    }
    return false;
}
int main()
{
    node* root=NULL;
    insertroot(root);
    levelordertraversal(root);
    int x;
    cin>>x;
    if(searchnode(root,x)){
        cout<<"present";
    }
    else{
        cout<<"absent";
    }
    return 0;
}