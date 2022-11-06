//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int index,int arr[],int N,int target){
        if(index>=N) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        bool inc= solve(index+1,arr,N,target-arr[index]);
        bool exc = solve(index+1,arr,N,target-0);
        
        return inc or exc;
        
        
    }
    
    
    bool solveMem(int index,int arr[],int N,int target,vector<vector<int>>& dp){
        if(index>=N) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        
        if(dp[index][target]!=-1) return dp[index][target];
        
        bool inc= solveMem(index+1,arr,N,target-arr[index],dp);
        bool exc = solveMem(index+1,arr,N,target-0,dp);
        
        return dp[index][target]=inc or exc;
    }
    
    bool solveTab(int N,int arr[],int total){
        // vector<vector<int>> dp(N+1,vector<int> (total+1,0));
        vector<int> curr(total+1,0);
        vector<int> next(total+1,0);
        curr[0]=1,next[0]=1;
        
        for(int index=N-1;index>=0;index--){
            for(int target= 0;target<= total/2;target++)
            {
                bool inc =0;
                if(target-arr[index]>=0)
                    inc= next[target-arr[index]];
                    
                bool exc = next[target-0];
        
                curr[target]=inc or exc;
            }
            next=curr;
        }
        
        return next[total/2];
    }
    
    int equalPartition(int N, int arr[])
    {
        int tot=0;
        for(int i=0;i<N;i++){
            tot+=arr[i];
        }
        if(tot&1) return 0;
        int target=tot/2;
        // code here
        // vector<vector<int>> dp(N,vector<int> (target+1,-1));
        // return solveMem(0,arr,N,target,dp);
        return solveTab(N,arr,tot);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends