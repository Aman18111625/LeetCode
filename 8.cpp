//Question : Unique Binary Search Trees(https://leetcode.com/problems/unique-binary-search-trees/)
//Difficulty Level:- Medium
//Pre-requisites:- Dynamic Programming on Trees

/*
Approach 1 (Catalan Number):
We can find the number of BST’s by thinking in recursive manner for ease:

Choose 1 as root, no element present on left-subtree. N-1 elements present on the right subtree.

Choose 2 as root, 1 element present on the left-subtree. N-2 elements present on the right-subtree.

Similarly, Choose i as root, i-1 elements present on the left-subtree. N-i elements on the right-subtree.

Then, Total number of BST’s C(N) = C(0)C(N-1) + C(1)C(N-2) +………+ C(i-1)C(N-i) +………….+ C(N-1)C(0).
where C(i) is the number of unique BST with i nodes.
*/
//TC:-O(N^2)
  int numTrees(int n) {
       vector<int>dp(n+1,0);
         dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                   dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
  }



Approach 2 (Recursive DP):

My intuition is that if we have numbers from 1 to N, then we will make each i as root once, and then send the nodes (1 to i-1) to theleft subtree and the nodes(i+1 to N) to theright subtree.

Note that the unique subtree for nodes (1 to X) is same as unique subtrees for (X+1 to 2X), i.e., if we have X number of nodes irrespective of their values then the unique BST for those nodes will be same no matter what value they holds. For eg: the nodes 3 4 5 will make same number of unique BST as the nodes with values 7 8 9 as the number of nodes is same.

So in our recursive solution, for a node i that will be root, then numTrees(i-1) will give answer for our left subtree for nodes (1 to i-1) and numTrees(N-i) will give answer for our right subtree for nodes (i+1 to n) because we will have (N-i) number of nodes in this range and we only care about the number of nodes.

And then the answer for our node i will be the product of answer of left subtree and answer of right subtree, i.e. , numTrees(i-1) * numTrees(N-i).

We will store our precomputed answers in our dp vector so that no repeated call is made for same number.

TC: O(N^2)

Here is the code for my approach mentioned above:

    int solve(int n, vector<int>&dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        
        int res{};
        
        for(int i{1}; i<=n; ++i)
            res += solve(i-1, dp)*solve(n-i, dp);
        
        return dp[n] = res;
    }
    
    int numTrees(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }