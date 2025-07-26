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
vector<int>zigzagtraversal(node* root){
    vector<int>result;
    //no root
    if(root==NULL){
        return result;
    }
    queue<node*>q;
    q.push(root);
    //flag for left to right and right to left
    bool lefttoright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>ans(size);
        //level process
        for(int i=0;i<size;i++){
            node* frontnode=q.front();
            q.pop();
            // normal or reverse insert
            int index;
            if(lefttoright){
                index=i;
            }
            else{
                index=size-i-1;
            }
                ans[index]=frontnode->data;
                if(frontnode->left){
                    q.push(frontnode->left);
                }
                if(frontnode->right){
                    q.push(frontnode->right);
                }
        }
        //direction change
        lefttoright=!lefttoright;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    vector<int>result=zigzagtraversal(root);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}