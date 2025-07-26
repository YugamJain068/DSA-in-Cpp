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
//function for creating B.T
node* buildtree(node* root){
    cout<<"enter the data: ";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    //creating left and right childs
    cout<<"write the data of left child of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"write the data of right child of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
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
void inorder(node* root){
    //inorder=LNR
    // base case
    if(root==NULL){
        return ;
    }
    // L->LEFT ME JAO
    inorder(root->left);
    // N->print karo
    cout<<root->data<<" ";
    // R->RIGHT ME JAO
    inorder(root->right);
}
void preorder(node* root){
    //preorder=NLR
    // base case
    if(root==NULL){
        return ;
    }
    // N->print karo
    cout<<root->data<<" ";
    // L->LEFT ME JAO
    preorder(root->left);
    // R->RIGHT ME JAO
    preorder(root->right);
}
void postorder(node* root){
    //postorder=LRN
    // base case
    if(root==NULL){
        return ;
    }
    // L->LEFT ME JAO
    postorder(root->left);
    // R->RIGHT ME JAO
    postorder(root->right);
    // N->print karo
    cout<<root->data<<" ";
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    cout<<"printinf the level order traversal output"<<endl;
    levelordertraversal(root);
    // 1 3 4 7 -1 -1 -1 6 -1 -1 5 8 -1 -1 9 -1 10 -1 -1
    cout<<"printing the inorder traversal output"<<endl;
    inorder(root);
    cout<<"\nprinting the preorder traversal output"<<endl;
    preorder(root);
    cout<<"\nprinting the postorder traversal output"<<endl;
    postorder(root);
    return 0;
}