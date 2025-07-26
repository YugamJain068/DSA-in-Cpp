#include<iostream>
#include<vector>
using namespace std;
void function(string input,string output,int index,string mapping[],string &ans){
    if(index>=input.length()){
        ans+=output;
        return ;
    }
    int number=input[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        function(input,output,index+1,mapping,ans);
        output.pop_back();
    }
}
int main()
{
    string input="23";
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index=0;
    string ans;
    string output="";
    function(input,output,index,mapping,ans);
    cout<<ans;
    return 0;
}