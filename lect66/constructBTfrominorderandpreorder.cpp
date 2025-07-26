#include<iostream>
#include<queue>
#include<map>
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
void createmapping(int inorder[],int n,map<int,int>&nodetoindex){
    for(int i=0;i<n;i++){
        nodetoindex[inorder[i]]=i;
        }
}
node* solve(int inorder[],int preorder[],int &preindex,int instartindex,int inendindex,int n,map<int,int>&nodetoindex){
    //BASE CASE
    if(preindex>=n || instartindex>inendindex){
        return NULL;
    }
    //taking index element(0 index element) as root element
    int element=preorder[preindex++];
    node* root=new node(element);
    //finding position of element in inorder
    int pos=nodetoindex[element];
    //left call in inorder
    root->left=solve(inorder,preorder,preindex,instartindex,pos-1,n,nodetoindex);
    //right call in inorder
    root->right=solve(inorder,preorder,preindex,pos+1,inendindex,n,nodetoindex);
    return root;
}
//function for creating B.T
node* buildtree(int inorder[],int preorder[],int n){
    int preorderindex=0;
    //creating nodes to index mapping to reduce time complexity
    map<int,int>nodetoindex;
    createmapping(inorder,n,nodetoindex);
    node* ans=solve(inorder,preorder,preorderindex,0,n-1,n,nodetoindex);
    //0---->inorderstartingindex,n-1---->inorderendingindex
    return ans;
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
    int inorder[6]={3,1,4,0,5,2};
    int preorder[6]={0,1,3,4,2,5};
    root=buildtree(inorder,preorder,6);
    //printing in postorder
    postorder(root);
}