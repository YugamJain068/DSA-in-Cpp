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
void leftpart(node* root,vector<int>&ans){
    //BASE CASE
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftpart(root->left,ans);
    }
    else{
        leftpart(root->right,ans);
    }
}
void leaftraverse(node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    //printing leaf node
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    leaftraverse(root->left,ans);
    leaftraverse(root->right,ans);
}
void rightpart(node* root,vector<int>&ans){
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right){
    rightpart(root->right,ans);
    }
    else{
    rightpart(root->left,ans);
    }
    //wapas aagye
    ans.push_back(root->data);
}
vector<int>boundarytraversal(node* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    //root print
    ans.push_back(root->data);
    //for left part
    leftpart(root->left,ans);
    //traverse leaf part of left subtree
    leaftraverse(root->left,ans);
    //traverse leaf part of right subtree
    leaftraverse(root->right,ans);
    //for right part
    rightpart(root->right,ans);
    return ans;
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    vector<int>result=boundarytraversal(root);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}