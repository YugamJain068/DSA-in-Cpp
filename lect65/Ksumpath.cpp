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
    if(data==-2){
        return NULL;
    }
    //creating left and right childs
    cout<<"write the data of left child of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"write the data of right child of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void ksumpath(node* root,vector<int>path,int k,int &count){
    //BASE CASE
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    //left call
    ksumpath(root->left,path,k,count);
    //right call
    ksumpath(root->right,path,k,count);
    //sum while returning
    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }
    //removing element from path while returning
    path.pop_back();
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    int k,count=0;
    vector<int>path;
    cout<<"write the value of k: "<<endl;
    cin>>k;
    ksumpath(root,path,k,count);
    cout<<"the number of paths in binary tree having sum "<<k<<" is "<<count<<endl;
    return 0;
}