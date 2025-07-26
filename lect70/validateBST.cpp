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
bool validateBST(node* root,int max,int min){
    if(root==NULL){
        return true;
    }
    //range check of data of root
    if(root->data>=min && root->data<=max){
        //left call
        bool left=validateBST(root->left,root->data,min);
        //right call
        bool right=validateBST(root->right,max,root->data);
        return left && right;
    }
    return false;
}
int main()
{
    node* root=NULL;
    insertroot(root);
    levelordertraversal(root);
    if(validateBST(root,10000,-10000)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}