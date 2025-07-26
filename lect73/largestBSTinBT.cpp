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
class info{
    public:
        int maxi;
        int mini;
        bool valid;
        int size;
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
info solve(node* root,int &maxsize){
    //BASE CASE
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    //left and right call
    info left=solve(root->left,maxsize);
    info right=solve(root->right,maxsize);
    info currnode;
    currnode.size=left.size+right.size+1;
    currnode.maxi=max(root->data,right.maxi);
    currnode.mini=min(root->data,left.mini);
    if(left.valid && right.valid && (root->data > left.maxi && root->data < right.mini)){
        currnode.valid=true;
    }
    else{
        currnode.valid=false;
    }
    //answer update
    if(currnode.valid){
        maxsize=max(maxsize,currnode.size);
    }
    return currnode;
}
int largestBSTinBT(node* root){
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    cout<<"printing the level order traversal output"<<endl;
    levelordertraversal(root);
    // 1 3 4 7 -1 -1 -1 6 -1 -1 5 8 -1 -1 9 -1 10 -1 -1
    int ans=largestBSTinBT(root);
    cout<<"\n\n"<<ans<<endl;
    return 0;
}