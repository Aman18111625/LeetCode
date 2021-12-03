//Question : Maximum Product Subarray(https://leetcode.com/problems/maximum-product-subarray/)
//Difficulty : Medium
//Pre-requisite: basics

   //Approach-1
    //TC:- O(N) SC:-O(1)
    int maxProduct(vector<int>& nums) {
      int n=nums.size();
       if (n== 0) return 0;
   // maxSub and minSub will hold the products till nums[i]
        int maxSub = nums[0];   
        int minSub = nums[0];
        int maxProductSub = nums[0];
        
        for (int i = 1; i<n; i++)
        {
            // element is negative so we swap max and min
            // because when multiplying negative with a negative, number becomes positive so minimum negative number will become the maximum number
            if (nums[i] < 0)
                swap(minSub, maxSub);
            // update all the sub values
             maxSub = max(maxSub * nums[i], nums[i]); 
            minSub = min(minSub * nums[i], nums[i]); 
            // choose max product to be the max between the maxProduct till now and maxSub
               maxProductSub = max(maxProductSub, maxSub); 
        }
        return maxProductSub;
    }
  //Approach-2 
  //TC:-O(N) SC:-O(1)
    int maxProduct(vector<int>& nums){
        int n=nums.size();
        if(n==0) return 0;
        int maxi=INT_MIN;
        int prod=1;
        //left to right
        for(int i=0;i<n;i++)
        {
            if(prod==0) prod=1; //if prod becomes zero then reset prod as 1
            prod*=nums[i];
            maxi=max(maxi,prod);
        }
        prod=1;
         //right to left
        for(int i=n-1;i>=0;i--)
        {
            if(prod==0) prod=1; //if prod becomes zero then reset prod as 1
            prod*=nums[i];
            maxi=max(maxi,prod);
        }
        return maxi;
    }

