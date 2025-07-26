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
void inorder(node* root,vector<int>&inorderroot){
    //inorder=LNR
    // base case
    if(root==NULL){
        return ;
    }
    // L->LEFT ME JAO
    inorder(root->left,inorderroot);
    // N->print karo
    inorderroot.push_back(root->data);
    // R->RIGHT ME JAO
    inorder(root->right,inorderroot);
}
bool twosumBST(node* root,int target){
    vector<int>inorderroot;
    inorder(root,inorderroot);
    int i=0,j = inorderroot.size()-1;
    while(i<j){
        int sum=inorderroot[i]+inorderroot[j];
        if(sum==target){
            return true;
        }
        if(sum>target){
            j--;
        }
        if(sum<target){
            i++;
        }
    }
    return false;
}
int main()
{
    node* root=NULL;
    insertroot(root);
    levelordertraversal(root);
    int target;
    cin>>target;
    if(twosumBST(root,target)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}