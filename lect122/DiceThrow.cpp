#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long solve(int dice, int faces, int target){
        // base case
        if(target < 0)
            return 0;
        if(dice == 0 && target != 0){
            return 0;
        }
        if(dice != 0 && target == 0){
            return 0;
        }
        if(dice == 0 && target == 0){
            return 1;
        }
        long long ans = 0;
        for(int i=1; i<=faces; i++){
            ans = ans + solve(dice-1, faces, target-i);
        }
        return ans;
    }
    
    long long solveMem(int dice, int faces, int target, vector<vector<long long>> &dp){
        // base case
        if(target < 0)
            return 0;
            
        if(dice == 0 && target != 0){
            return 0;
        }
        
        if(dice != 0 && target == 0){
            return 0;
        }
        
        if(dice == 0 && target == 0){
            return 1;
        }
        
        if(dp[dice][target] != -1)
            return dp[dice][target];
        
        long long ans = 0;
        
        for(int i=1; i<=faces; i++){
            ans = ans + solveMem(dice-1, faces, target-i, dp);
        }
        
        return dp[dice][target] = ans;
        
    }
    
    long long solveTab(int d, int f, int t){
        
        vector<vector<long long>> dp(d+1, vector<long long>(t+1, 0));
        
        // After analyzing base cases
        dp[0][0] = 1;
        
        
        for(int dice = 1; dice <= d; dice++){
            for(int target = 1; target <= t; target++){
                
                long long ans = 0;
        
                for(int i=1; i<=f; i++){
                    
                    if(target-i >= 0)
                        ans = ans + dp[dice-1][target-i];
                }
                
                dp[dice][target] = ans;
            }
        }
        
        return dp[d][t];
        
    }
    
    long long solveSpaceOP(int d, int f, int t){
         
        vector<long long> prev(t+1, 0);
        vector<long long> curr(t+1, 0);
        
        // After analyzing base cases
        prev[0] = 1;
        
        for(int dice = 1; dice <= d; dice++){
            for(int target = 1; target <= t; target++){
                
                long long ans = 0;
        
                for(int i=1; i<=f; i++){
                    
                    if(target-i >= 0)
                        ans = ans + prev[target-i];
                }
                
                curr[target] = ans;
            }
            
            prev = curr;
        }
        
        return prev[t];
    }
int main()
{
    int dices,faces,target;
    cout<<"write the no. of dices,faces and the target: ";
    cin>>dices>>faces>>target;
    //int ans=solve(dices,faces,target);
    //vector<vector<long long>>dp(dices,vector<long long>(target+1,-1));
    //int ans=solveMem(dices,faces,target,dp);
    //int ans=solveTab(dices,faces,target);
    int ans=solveSpaceOP(dices,faces,target);
    cout<<ans;
    return 0;
}