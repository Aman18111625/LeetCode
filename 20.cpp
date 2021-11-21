//Question:- Single Element in a Sorted Array
//Difficulty : Medium
//Pre-requisite: Binary Search

   /* Approach-1 TC:=>O(N) SC:=>O(1)
    simple find xor of given array->according to the question every element appears except one number and we know xor of same number ->0 so Xor of given array is our answer 
    int singleNonDuplicate(vector<int>& nums) {
        int Xor=0;
        int n=nums.size();
        for(int i=0;i<n;i++) Xor^=nums[i];
        return Xor;
    }
    */
    //Optimal Approach
    //TC:- O(logN) SC:-O(1)
//try to run in some testcase you'll get observation.
      int singleNonDuplicate(vector<int>& nums){
          if(nums.size()==1) return nums[0];
          int low=0,high=nums.size()-1;
          while(low<=high)
          {
             int mid=low+(high-low)/2;
             if(mid%2)
             {
                 //even-odd pair->answer lies in the right part of the array
              if(nums[mid-1]==nums[mid])
                  low=mid+1;
              else//even-odd pair violated-> answer lies in the left part
                  high=mid-1;
             }else
             {
                 //even odd pair->we're on the left part but answer lies in the right part 
                 if(nums[mid]==nums[mid+1])
                      low=mid+1;
                 else //same pair violated->answer lies in the left part
                     high=mid-1;
             }
          }
          return nums[low];
      }