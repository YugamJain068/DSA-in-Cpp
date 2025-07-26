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
int countnodes(node* root){
    if(root==NULL){
        return 0;
    }
    int ans=1+countnodes(root->left)+countnodes(root->right);
    return ans;
}
bool isCBT(node* root,int count,int index){
    if(root==NULL){
        return true;
    }
    if(index>=count){
        return false;
    }
    else{
        bool left=isCBT(root->left,count,2*index+1);
        bool right=isCBT(root->right,count,2*index+2);
        return (left && right);
    }
}
bool ismaxorder(node* root){
    //leaf nodes
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left=ismaxorder(root->left);
        bool right=ismaxorder(root->right);
        return (left && right && root->data>root->left->data && root->data>root->right->data);
    }
}
bool isBSTheap(node* root){
    int index=0;
    int count=countnodes(root);
    if(isCBT(root,count,index) && ismaxorder(root)){
        return true;
    }
    return false;
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    if(isBSTheap(root)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}