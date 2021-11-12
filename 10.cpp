//Question:- Minimum value to Get Positive step by step sum(https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/)
//Difficulty:- Easy
//Pre-requisite:- Prefix-sum
//We have to return the minimum positive value of startValue such that the step by step sum is never less than 1
 
  int minStartValue(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]>0?nums[0]:abs(nums[0])+1;//if n==1 then check if it is >0 then return same else return absolute value +1 
        int cur=0,mini=0;
        for(int i=0;i<n;i++)
        {
            cur+=nums[i];//add nums[i] to cur
            if(mini>cur) //if cur<mini then update mini
                 mini=cur;
        }
        return -mini+1;
    }