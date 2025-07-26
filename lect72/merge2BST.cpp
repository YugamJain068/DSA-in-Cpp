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
vector<int> mergeBST(vector<int>in1,vector<int>in2){
    vector<int>ans(in1.size()+in2.size());
    int i=0,j=0,k=0;
    while(i<in1.size() && j<in2.size()){
        if(in1[i]<in2[j]){
            ans[k++]=in1[i];
            i++;
        }
        else{
            ans[k++]=in2[j];
            j++;
        }
    }
    while(i<in1.size()){
        ans[k++]=in1[i];
            i++;
    }
    while(j<in2.size()){
        ans[k++]=in2[j];
            j++;
    }
    return ans;
}
node* inordertoBST(int s,int e,vector<int>&in){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node* root=new node(in[mid]);
    root->left=inordertoBST(s,mid-1,in);
    root->right=inordertoBST(mid+1,e,in);
    return root;
}
//function for merging 2 BST
node* merge2BST(node* root1,node* root2){
    //creation of inorder vector of BST1 and BST 2 
    vector<int>in1,in2;
    inorder(root1,in1);
    inorder(root2,in2);
    //merging both in1 and in2
    vector<int>ans;
    ans=mergeBST(in1,in2);
    //converting inorder to BST
    int s=0,e=ans.size()-1;
    return inordertoBST(s,e,ans);
}
int main()
{
    node* root1=NULL;
    insertroot(root1);
    levelordertraversal(root1);
    cout<<endl<<endl;
    node* root2=NULL;
    insertroot(root2);
    levelordertraversal(root2);
    cout<<endl<<endl;
    node* root=NULL;
    root=merge2BST(root1,root2);
    levelordertraversal(root);
    return 0;
}