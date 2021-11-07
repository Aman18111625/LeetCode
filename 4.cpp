//Question: Sum Of Left Leaves (https://leetcode.com/problems/sum-of-left-leaves/)
//Difficulty level: Easy

//BFS Approach
 int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
             TreeNode *node=q.front();
               q.pop();
            if(node->left)
            {
            if(node->left->left==NULL and node->left->right==NULL) sum+=node->left->val;
            else q.push(node->left);
            }
            if(node->right) q.push(node->right);
           }
        }
        return sum;
    }