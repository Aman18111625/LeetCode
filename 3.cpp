//Question:- Sum Root Of Leaf Numbers (https://leetcode.com/problems/sum-root-to-leaf-numbers/)
//Pre-requisite:- Binary Tree

int helper(TreeNode *root,int sum=0)
{
         if(!root) return 0;//if root is null then simply return 0
        sum=(sum*10)+root->val;//calculate sum
        if(!root->left and !root->right) return sum;//if a leaf node then simply return sum
      int l=helper(root->left,sum);//call for left tree
      int r=helper(root->right,sum);//call for right tree
        return l+r;
}

int sumNumbers(TreeNode* root)
{
        if(!root) return 0;//if root is null return 0;
         return helper(root);//call to helper function
}