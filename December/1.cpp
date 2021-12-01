//Question : House Robber(https://leetcode.com/problems/house-robber/)
//Difficulty : Medium
//Pre-requisites : Recursion + Dynamic Programming


 //Recursive Approach :- TC:O(2^N) SC:-O(N)(stack space)
    int helper(vector<int>&nums, int i){
        if(i>=nums.size()){
            return 0;
        }
        int a = helper(nums, i+2) + nums[i];
        int b = helper(nums, i+1);
        return max(a,b);
    }
     int rob(vector<int>& nums){
      return helper(nums,0);
     }

     //Recursive + memoization
   //TC:-O(N) SC:-O(N)
     int dp[102];
     int helper(vector<int>&nums,int i)
     {
     if(i>=nums.size()) return 0;
     if(dp[i]!=-1) return dp[i];
     return dp[i]=max(helper(nums,i+2)+nums[i],helper(nums,i+1));
     }
     
     int rob(vector<int>&nums)
     {
       memset(dp,-1,sizeof(dp)) ;
       return helper(nums,0);
     }
   
//Top-Down
  TC:-O(N) SC:-O(N)
    int rob(vector<int>& nums) {
         int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp(n+1,0);
         dp[1]=nums[0];
       for(int i=2;i<=n;i++)
       {
           dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
       }
        return dp[n];
    }