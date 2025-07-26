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
node* LCA(node* root,int n1,int n2){
    //BASE CASE
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* leftans=LCA(root->left,n1,n2);
    node* rightans=LCA(root->right,n1,n2);
    if(leftans!=NULL && rightans==NULL){
        return leftans;
    }
    else if(leftans==NULL && rightans!=NULL){
        return rightans;
    }
    else if(leftans!=NULL && rightans!=NULL){
        return root;
    }
    else{
        return NULL;
    }
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    int n1,n2;
    printf("enter the value of n1: ");
    scanf("%d",&n1);
    printf("enter the value of n2: ");
    scanf("%d",&n2);
    int ans=LCA(root,n1,n2)->data;
    cout<<"LCA of "<<n1<<" and "<<n2<<" is: "<<ans<<endl;
    return 0;
}