//Question : Largest Divisible Subset
//Difficulty : Medium
//Pre-requisites: LIS Problem

//Time Complexity: - O(N^2) +(NLOGN) + O(N)
//Space Complexity:- O(N)
   vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());// if we sort than we can say b<=a ->so we need to only if a%b==0 otherwise we need to check -> a%b==0 or b%a==0
        vector<int>dp(n+1,1);//to store length of subset ATQ
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                 if(nums[i]%nums[j]==0 and 1+dp[j]>dp[i])
                 {
                     dp[i]=1+dp[j];
                    if(maxi<dp[i]) maxi=dp[i];
                 }
            }
        }
        int prev=-1;
        for(int i=n-1;i>=0;i--)
        {
        if(dp[i]==maxi && (prev%nums[i]==0 or prev==-1))//if dp[i]==maxi then push in ans
            {
                ans.push_back(nums[i]);
                maxi--;
                prev=nums[i];
            }
        }
        return ans;
    }