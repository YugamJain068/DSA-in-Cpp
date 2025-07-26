#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    //constructor
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
node* BSTfrompreorder(vector<int>&preorder,int mini,int maxi,int &i){
    //BASE CASE
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    //creation of new root
    node* newroot=new node(preorder[i++]);
    newroot->left=BSTfrompreorder(preorder,mini,newroot->data,i);
    newroot->right=BSTfrompreorder(preorder,newroot->data,maxi,i);
    return newroot;
}
int main()
{
    node* root=NULL;
    vector<int>preorder={20,10,5,15,13,35,30,42};
    int mini=INT16_MIN;
    int maxi=INT16_MAX;
    int i=0;
    node* newroot=NULL;
    newroot=BSTfrompreorder(preorder,mini,maxi,i);
    levelordertraversal(newroot);
    return 0;
}