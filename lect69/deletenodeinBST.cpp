#include<iostream>
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
node* insertintoBST(node* root,int d){
    //BASE CASE
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d<root->data){
        //left call 
        root->left=insertintoBST(root->left,d);
    }
    else{
        //right call 
        root->right=insertintoBST(root->right,d);
    }
    return root;
}
void insertroot(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertintoBST(root,data);
        cin>>data;
    }
}
int minnode(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int maxnode(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
node* deletenode(node* root,int val){
    //BASE CASE
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        //0 child 
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minnode(root->right);
            root->data=mini;
            root->right=deletenode(root->right,mini);
            return root;
        }
    }
    else if(root->data>val){
        //left part
        root->left=deletenode(root->left,val);
        return root;
    }
    else if(root->data<val){
        //right part
        root->right=deletenode(root->right,val);
        return root;
    }
    return root;
}
int main()
{
    node* root=NULL;
    insertroot(root);
    levelordertraversal(root);
    deletenode(root,110);
    levelordertraversal(root);
    return 0;
}