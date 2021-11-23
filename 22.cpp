//Question : Delete Node in a BST
//Difficulty : Medium
//Pre-requisite: Binary Search Tree

/*
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 */
    //return max of right subtree
    int max(TreeNode* root)
    {
         if(root->right)  return max(root->right);
         return root->val;
    }
  
    TreeNode* deleteNode(TreeNode* root, int data) {
     if(!root) return NULL;
     if(data>root->val) // if data> root->val then we need to search in right subtree
     {
       root->right=deleteNode(root->right,data);
     }
     else if(data<root->val) //if data<root->val then we need to search in left subtree
     {
       root->left=deleteNode(root->left,data);
     }
     else//data==root->val
     {
//case->1 if left-child and right-child both are present
        if(root->left and root->right)
        {
            int lmax=max(root->left);//find max of left subtree and replace it with root->val and then delete that node
            root->val=lmax;
            root->left=deleteNode(root->left,lmax);
            return root;
        }
        else if(root->left) //if root->right is not exist then simply replace with root->left
        {
            return root->left;
        }else if(root->right)//if root->left is not exist then simply replace with root->right
        {
            return root->right;
        }
        else //if to be deleted node is a leaf node 
        {
            return NULL;
        }
      }
    return root;
    }
    */