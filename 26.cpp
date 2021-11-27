//Question : Search Insert Position (https://leetcode.com/problems/search-insert-position/)
//Difficulty : Easy
//Pre-requisite: Binary Search


//Time Complexity : O(logN) 
//Space Complexity: O(1)
int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
