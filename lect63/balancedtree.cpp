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
pair<bool,int> balancedtree(node* root){
    //BASE CASE
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    pair<bool,int>leftans=balancedtree(root->left);
    pair<bool,int>rightans=balancedtree(root->right);
    int op1=leftans.first;
    int op2=rightans.first;
    bool diff=abs(leftans.second-rightans.second)<=1;
    pair<bool,int>ans;
    ans.second=max(leftans.second,rightans.second)+1;
    if(leftans.first && rightans.first && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    } 
    return ans;
}
bool balanced(node* root){
    return balancedtree(root).first;
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    if(balanced(root)){
        cout<<"tree is balanced";
    }
    else{
        cout<<"tree is not balanced";
    }
    return 0;
}