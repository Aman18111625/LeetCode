//Question :- Product of Array Except Self(https://leetcode.com/problems/product-of-array-except-self/)
//Difficulty : Medium
//Pre-requisited: Nothing

//Brute-Force
//Time -Complexity: O(N^2)
//Space -Complexity: O(1)

 vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                ans[i] = ans[i] * nums[j]; 
            }
        }

        return ans;
    }

//better
//Time -Complexity: O(N)
//Space -Complexity: O(N)

/*
Let's assume your initial array is [1,2,3,4,5,6]: if you prepare a result vector res of the required size (same as nums) and set the first value to 1 (the neuter element in multiplications), you can go on up to the end setting each cell to be the product of the previous one, plus the matching previous slot in nums.
In our case, after the first pass, we will have [1,1,2,6,24,120] - and please note that the last element is already of the expected value.
Now, for the second pass, we have to start from the opposite direction (I started from left first, so I will go right now - you can try the other way around, if you want some extra challenge) and multiply each value (other than the rightmost: we are already fine with that) by prod, initially set to be of the value of the last element (so, in our case, the "previous" element, since we start from the penultimate one, in the same guise we started from the second element in the first loop) and then gradually incremented by nums[i] AFTER we have multiplying the ith cell.
The second loop will give us [720,360,240,180,144,120], which is precisely what we wanted, so it means we are done and can now return res .
*/

  vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size(),1);
        vector<int>right(nums.size(),1);
        //1.right product
        int prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
         prod*=nums[i];
         right[i]=prod;
        }
        //2.result product
        prod=1;
        for(int i=0;i<nums.size()-1;i++)
        {
        int lp=prod;
        int rp=right[i+1];
        res[i]=(lp*rp);
        prod*=nums[i];
        }
        res[nums.size()-1]=prod;
        return res;
    }

//Best Solution
//Time - Complexity: O(N) 
//Space - Complexity: O(1)

vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n);
        
        ans[n - 1] = 1; // ans array used as right product array
        
        for(int i = n - 2; i >= 0; i--){
            ans[i] = nums[i + 1] * ans[i + 1];
        }
        
        int leftProd = 1;
        for(int i = 0; i < n; i++){
            ans[i] = leftProd * ans[i];
            leftProd = leftProd * nums[i];
        }
        
        return ans;
    }