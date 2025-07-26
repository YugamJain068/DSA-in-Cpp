#include<iostream>
#include<stack>
using namespace std;
bool redundant(string a){
    stack<char>s;
    for(int i=0;i<a.length();i++){
        char ch=a[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            s.push(ch);
        }
        else{
        if(ch==')'){
            bool isredundant=true;
            while(s.top()!='('){
                char top=s.top();
                if(top=='+' || top=='-' || top=='*' || top=='/'){
                    isredundant=false;
                }
                s.pop();
            }
            if(isredundant==true){
                return true;
            }
                s.pop();
        }
    }
    }
    return false;
}
int main()
{
    string a="(a+(a+b))"; 
    if(redundant(a)){
        cout<<"the brackets are redundant"<<endl;
    }
    else{
        cout<<"the brackets are not redundant"<<endl;
    }
    return 0;
}