#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    int countWays(int n, int sum) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        int ans= ways(n,0,sum,n,dp);
        if(ans==0) return -1;
        return ans;
    }
    int ways(int ind,int sum,int target,int n,vector<vector<int>>& dp){
        if(ind==0){
            return (sum==target);
        }
        if(target<sum) return 0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int start=(ind==n)? 1:0;
        int cnt=0;
        for(int i=start;i<=9;i++){
            cnt+=ways(ind-1,sum+i,target,n,dp);
        }
        return dp[ind][sum]=cnt;

        
    }
};
int main(){
    Solution sol;
    int n,sum;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    cout<<"Enter the value of sum"<<endl;
    cin>>sum;
    cout<<"Total number of ways are "<<sol.countWays(n,sum)<<endl;
    return 0;
}