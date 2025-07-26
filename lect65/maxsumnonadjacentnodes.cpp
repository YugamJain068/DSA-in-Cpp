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
pair<int,int> solve(node* root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    //left call
    pair<int,int>leftans=solve(root->left);
    //right call
    pair<int,int>rightans=solve(root->right);
    pair<int,int>result;
    //we are including root so we are excluding left and right off root
    result.first=root->data+leftans.second+rightans.second;
    //now we are excluding root so we are including left and right off root
    result.second=max(leftans.first,leftans.second)+max(rightans.first,rightans.second);
    return result;
}
int maxsumnonadjacent(node* root){
    pair<int,int>ans=solve(root);
    return max(ans.first,ans.second);
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    cout<<"max sum of non adjacent node is: "<<maxsumnonadjacent(root);
    return 0;
}