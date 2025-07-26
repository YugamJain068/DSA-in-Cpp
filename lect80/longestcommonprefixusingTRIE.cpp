#include<iostream>
#include<string>
#include<vector>
using namespace std;
class trienode{
    public:
        char data;
        trienode* children[26];
        int childcount;
        bool isterminal;
    trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
         isterminal=false;
         childcount=0;
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

            //assumtion - word will not be in caps
            int index=word[0]-'a';
            trienode* child;
            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            //absent
            else{
                child=new trienode(word[0]);
                root->childcount++;
                root->children[index]=child;
            }
            //recursion
            insertutil(child,word.substr(1));
        }
        void insertword(string word){
            insertutil(root,word);
        }
        void lcp(string str,string &ans){
            for(int i=0;i<str.size();i++){
                char ch=str[i];
                if(root->childcount==1){
                    ans.push_back(ch);
                    //aage bhadjao
                    int index=ch-'a';
                    root=root->children[index];
                }
                else{
                    break;
                }
                if(root->isterminal){
                    break;
                }
            }
        }
};
int main()
{
    trie *t=new trie();
    vector<string>arr={"coding","codezer","codingninja","coders"};
    for(int i=0;i<arr.size();i++){
        t->insertword(arr[i]);
    }
    string first=arr[0];
    string ans="";
    t->lcp(first,ans);
    cout<<ans;
    return 0;
}