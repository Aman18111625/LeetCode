//Question : Binary Tree Tilt(https://leetcode.com/problems/binary-tree-tilt/)
//Difficulty : Easy
//Pre-requisites: what is binary tree.

//Always try  to remember don't change input
//Time- Complexity : O(H) where H->height of tree 
//Space-Complexity : O(N)//using  vector to store res
    vector<int>tilt;//store abs diff
    int helper(TreeNode* root)
    {
        if(!root) return 0;
        int left=helper(root->left);//call for left subtree
        int right=helper(root->right);//call for right subtree
        tilt.push_back(abs(left-right));
        return root->val+left+right;//return sum of root & left & right subtree
    }

    int findTilt(TreeNode* root) {
        tilt.clear();
        helper(root);
        int sum=0;
        for(auto &t: tilt) sum+=t;
        return sum;
    }

