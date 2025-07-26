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
node* solve(node* root,int nodedata,int &k){
    //BASE CASE
    if(root==NULL){
        return NULL;
    }
    if(root->data==nodedata){
        return root;
    }
    //leftcall
    node* leftans=solve(root->left,nodedata,k);
    //rightcall
    node* rightans=solve(root->right,nodedata,k);
    //wapas aagye
    if(leftans!=NULL && rightans==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans==NULL && rightans!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int kthancestor(node* root,int nodedata,int k){
    node* ans=solve(root,nodedata,k);
    //if nodedata is data of rootnode and k is given to be between 1 too 100 in question so we can't find it answer ans then we will return -1
    if(ans==NULL || ans->data==nodedata){
        return -1;
    }
    return ans->data;
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    int nodedata,k;
    cout<<"enter the value of data whose kth ancestor you wnt to find and also enter the value of k: ";
    cin>>nodedata>>k;
    cout<<"the "<<k<<"th ancestor of node "<<nodedata<<" is: "<<kthancestor(root,nodedata,k)<<endl;
    return 0;
}