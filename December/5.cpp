//Question : House Robber III(https://leetcode.com/problems/house-robber-iii/)
//Difficulty : Medium
//Pre-requisites : House Robber-I && House Robber-II

//Time Complexity : O(N) Space-Complexity : O(H) 
//N->number of nodes in Tree 
//H->Height of tree
     pair<int,int> findMaxMoney (TreeNode* root) {
        if (!root) return {0, 0};
        int choose, not_choose;//for every node we have two choice we can choose it or skip it if we choose node then we need to skip it's left and right and if we do not choose node then take max of  left+right
        pair<int,int> left = findMaxMoney(root->left);
        pair<int,int> right = findMaxMoney(root->right);
        choose = root->val + left.second+right.second;//op1
        not_choose = max(left.first, left.second) +  max(right.first, right.second);//op2
        return {choose, not_choose};
    }

    int rob(TreeNode* root) {
        if(!root->left and !root->right) return root->val;
         auto ans=findMaxMoney(root);
        return max(ans.first,ans.second);
    }