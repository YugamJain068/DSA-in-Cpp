#include<iostream>
#include<string>
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
        bool searchutil(trienode* root,string word){
            if(word.length()==0){
                    return root->isterminal;
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
                return false;
            }
            return searchutil(child,word.substr(1));
        }
        bool searchword(string word){
            return searchutil(root,word);
        }
};
int main()
{
    trie *t=new trie();
    t->insertword("YUGAM");
    cout<<"present or not: "<<t->searchword("YUG")<<endl;
    cout<<"present or not: "<<t->searchword("YUGAM")<<endl;
    cout<<"present or not: "<<t->searchword("YUGAMA")<<endl;
    return 0;
}