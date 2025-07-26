#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&obs){
    int n=obs.size()-1;
    vector<int>curr(4,INT_MAX);
    vector<int>next(4,INT_MAX);
    next[0]=0;
    next[1]=0;
    next[2]=0;
    next[3]=0;
    //dp[currpos][currlane]=curr[currlane]
    //dp[currpos][currlane+1]=next[currlane]
    for(int currpos=n-1;currpos>=0;currpos--){
        for(int currlane=1;currlane<=3;currlane++){
            if(obs[currpos+1]!=currlane){
                curr[currlane]=next[currlane];
            }
            else{
                //SIDEWAYS JUMP
                int ans=INT_MAX;
                for(int i=1;i<=3;i++){
                    if(currlane!=i && obs[currpos]!=i){
                        ans=min(ans,1+next[i]);
                    } 
                }
                curr[currlane]=ans;
            }
        }
        next=curr;
    }
    return min(next[2],min(1+next[1],1+next[3]));
}
int main()
{
    int n;
    cout<<"wirte size of obstacles vector: ";
    cin>>n;
    vector<int>obs(n);
    for(int i=0;i<n;i++){
        cin>>obs[i];
    }
    int ans=solve(obs);
    cout<<ans;
    return 0;
}