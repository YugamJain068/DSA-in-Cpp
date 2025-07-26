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
void bloodline(node* root,int length,int &maxlength,int sum,int &maxsum){
    //BASE CASE
    if(root==NULL){
        if(length>maxlength){
            maxlength=length;
            maxsum=sum;
        }
        else if(length==maxlength){
            maxsum=max(sum,maxsum);
        }
        return;
    }
        sum+=root->data;
        bloodline(root->left,length+1,maxlength,sum,maxsum);
        bloodline(root->right,length+1,maxlength,sum,maxsum);
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    int length=0;
    int maxlength=0;
    int sum=0;
    int maxsum=INT_MIN;
    bloodline(root,length,maxlength,sum,maxsum);
    cout<<"sum of nodes on longest path from root to leaf node is "<<maxsum<<endl;
    return 0;
}