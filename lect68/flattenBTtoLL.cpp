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
void flattenBTtoLL(node* &root){
    node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            //finding predecessor of current
            node* pred=curr->left;
            while(pred->right){
                pred=pred->right;
            }
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
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
int main()
{
    node* root=NULL;
    root=buildtree(root);
    flattenBTtoLL(root);
    inorder(root);
}