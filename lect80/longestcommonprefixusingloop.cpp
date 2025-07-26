#include<iostream>
#include<vector>
#include<string>
using namespace std;
string solve(vector<string>&arr){
    string ans;
    bool match = true;
    for(int i=0;i<arr[0].length();i++){
            char ch=arr[0][i];
            for(int j=1;j<arr.size();j++){
                if(ch!=arr[j][i]){
                    match=false;
                    break;
                }
            }
            if(match==false){
                break;
            }
            else{
                ans.push_back(ch);
            }
    }
    return ans;
}
int main()
{
    vector<string>arr={"coding","codezer","codingninja","coders"};
    string ans;
    ans=solve(arr);
    cout<<ans;
    return 0;
}