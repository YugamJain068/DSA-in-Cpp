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
void rightview(node* root,vector<int>&ans,int level){
    //BASE CASE
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    rightview(root->right,ans,level+1);
    rightview(root->left,ans,level+1);
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    vector<int>ans;
    rightview(root,ans,0);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}