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
bool identicaltree(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
    bool left=identicaltree(root1->left,root2->left);
    bool right=identicaltree(root1->right,root2->right);
    bool value=root1->data==root2->data;
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    node* root1=NULL;
    node* root2=NULL;
    root1=buildtree(root1);
    root2=buildtree(root2);
    if(identicaltree(root1,root2)){
        cout<<"both trees are identical";
    }
    else{
        cout<<"tress are not identical";
    }
    return 0;
}