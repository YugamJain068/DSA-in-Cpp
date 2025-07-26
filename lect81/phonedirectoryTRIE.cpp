#include<iostream>
#include<string>
#include<vector>
using namespace std;
class trienode{
    public:
        char data;
        trienode* children[26];
        bool isterminal;
    trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
         isterminal=false;
    } 
};
class trie{
    public:
    trienode* root;
    trie(){
        root=new trienode('\0');
    }
        void insertutil(trienode* root,string word){
            //base case:
            if(word.length()==0){
                root->isterminal=true;
                return;
            }

            //assumtion - word will be in caps
            int index=word[0]-'A';
            trienode* child;
            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            //absent
            else{
                child=new trienode(word[0]);
                root->children[index]=child;
            }
            //recursion
            insertutil(child,word.substr(1));
        }
        void insertword(string word){
            insertutil(root,word);
        }
};
int main()
{
    trie *t=new trie();
    vector<string>arr={"cod","coding","codding","code","coly"};
    for(int i=0;i<arr.size();i++){
        string str=arr[i];
        t->insertword(str);
    }
    
    return 0;
}