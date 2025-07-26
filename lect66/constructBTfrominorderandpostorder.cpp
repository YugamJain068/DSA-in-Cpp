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
node* solve(int inorder[],int postorder[],int &postorderindex,int instartindex,int inendindex,int n,map<int,int>&nodetoindex){
    //BASE CASE
    if(postorderindex<0 || instartindex>inendindex){
        return NULL;
    }
    //taking index element(0 index element) as root element
    int element=postorder[postorderindex--];
    node* root=new node(element);
    //finding position of element in inorder
    int pos=nodetoindex[element];
    //in case of inorder/postorder we first build right subtree
    //right call in inorder
    root->right=solve(inorder,postorder,postorderindex,pos+1,inendindex,n,nodetoindex);
    //left call in inorder
    root->left=solve(inorder,postorder,postorderindex,instartindex,pos-1,n,nodetoindex);
    return root;
}
//function for creating B.T
node* buildtree(int inorder[],int postorder[],int n){
    int postorderindex=n-1;
    //creating nodes to index mapping to reduce time complexity
    map<int,int>nodetoindex;
    createmapping(inorder,n,nodetoindex);
    node* ans=solve(inorder,postorder,postorderindex,0,n-1,n,nodetoindex);
    //0---->inorderstartingindex,n-1---->inorderendingindex
    return ans;
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
int main()
{
    node* root=NULL;
    int inorder[8]={4,8,2,5,1,6,3,7};
    int postorder[8]={8,4,5,2,6,7,3,1};
    root=buildtree(inorder,postorder,8);
    //printing in preorder
    preorder(root);
}