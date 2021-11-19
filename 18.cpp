//Question : - Find All Numbers Disappeared in an Array(https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
//Difficulty : Easy
//Pre-requisite: Cycle Sort

   vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        if(n==1 && nums[0]==1) return {}; 
        int i=0;
        //cycle sort
 //we know here numbers are in range [1,n] so correct position of each number is nums[i]-1 
        while(i<n)
        {
            int correct=nums[i]-1;//find correct position
            if(nums[i]!=nums[correct])//swap if number is not at correct position
                swap(nums[i],nums[correct]);
            else i++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
    if(nums[i]!=i+1) ans.push_back(i+1);//now check is nums[i]!=i+1 then number is missing
        }
        return ans;
    }