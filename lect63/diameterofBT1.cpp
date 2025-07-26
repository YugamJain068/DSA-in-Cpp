#include<iostream>
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
int height(node* root){
    //BASE CASE
    if(root==NULL){
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    int ans=max(leftheight,rightheight)+1;
    return ans;
}
int diameter(node* root){
    //BASE CASE
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+1+height(root->right);
    int ans=max(op1,max(op2,op3));
    return ans;
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    cout<<"the diameter of Binary Tree is: "<<diameter(root)<<endl;
    return 0;
}