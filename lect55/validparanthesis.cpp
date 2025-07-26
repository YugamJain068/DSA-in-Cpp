#include<iostream>
#include<stack>
using namespace std;
bool isparanvalid(string paran){
    stack<char>s;
    for(int i=0;i<paran.length();i++){
        char ch=paran[i];
        if(ch=='{' || ch=='[' || ch=='('){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.top();
                if((ch=='}' && top=='{') || (ch==']' && top=='[') || (ch==')' && top=='(')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    string paran="({[()]})";
    if(isparanvalid(paran)){
        cout<<"the paranthesis is valid"<<endl;
    }
    else{
        cout<<"the paranthesis is not valid"<<endl;
    }
    return 0;
}