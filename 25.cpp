//Question :- Maximum Subarray (https://leetcode.com/problems/maximum-subarray/)
//Difficulty : Easy
//Pre-requisite : Kadane's Algorithm

    //Approach -1 run three loop first two for generating all the subarrays and third loop for get sum of each subarray -> find maximum of them 
    //Time Complexity:- O(N^3) Space Complexity:- O(1)
    
    /*
    //Approach-2 run two loop for generating all the subarrays and get maximum sum of them
    //TC: O(N^2) SC:- O(N)
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            int curr_sum = 0;
            for(int j=i; j<nums.size(); j++){
                curr_sum += nums[j];
                //cout<<curr_sum<<endl;
                max_sum = max(max_sum, curr_sum);
            }
        }
    return max_sum;
    }
    */
    //Approach-3 Using Kadane's Algorithm
    //TC:- O(N) SC:- O(1)
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=INT_MIN;
        int fact=0;
        for(int i=0;i<n;i++)
        {
            fact+=nums[i];
            sum=max(fact,sum);
            fact=max(fact,0);
        }
        return sum;
    }