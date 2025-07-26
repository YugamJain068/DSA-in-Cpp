#include<iostream>
#include<map>
#include<queue>
#include<string>
using namespace std;
int main()
{
    map<char,int>count;
    queue<int>q;
    string st="aabbcdcf";
    string ans="";
    for(int i=0;i<st.size();i++){
        char ch=st[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty()){
            if(count[q.front()]>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    cout<<ans;
    return 0;
}