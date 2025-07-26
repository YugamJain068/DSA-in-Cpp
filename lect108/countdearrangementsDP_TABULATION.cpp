#include <bits/stdc++.h>
using namespace std;
int count(int n){
    vector<int>dp(n+1,0);
   dp[1]=0;
   dp[2]=1;
   for(int i=3;i<=n;i++){
    int a=dp[i-1];
    int b=dp[i-2];
    int sum=a+b;
    int ans=(i-1)*sum;
    dp[i]=ans;
   }
   return dp[n];
}
//space optimisation
int count_2(int n){
   int prev2=0;
   int prev1=1;
   for(int i=3;i<=n;i++){
    int a=prev1;
    int b=prev2;
    int sum=a+b;
    int ans=(i-1)*sum;
    prev2=prev1;
    prev1=ans;
   }
   if(n==1){
    return 0;
   }
   return prev1;
}
int main()
{
    vector<int>arr;
    int n;
    cout<<"write n: ";
    cin>>n;
    //int ans=count(n);
    int ans=count_2(n);
    cout<<ans;
    return 0;
}